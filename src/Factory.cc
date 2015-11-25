
#include "Factory.hh"
#include "evaluators.hh"
#include "PrintingEvaluator.hh"
#include "operands.hh"
#include "operations.hh"
#include "Tokenizer.hh"

#include <iostream>
#include <stdexcept>
#include <list>
#include <stack>
#include <string>



//
// Edsger Dijkstra invented the Shunting-yard algorithm to convert infix expressions to postfix (RPN).
//
// http://scriptasylum.com/tutorials/infix_postfix/algorithms/infix-postfix/index.htm
// http://everything2.com/title/Infix+to+postfix+conversion+algorithm


void Factory::transform(
        std::ostream & aResultPostfixExpression,
        const std::string & aInfixExpression,
        const std::string & aOperations )
{
    init_precedencetab();
    std::stack<char> op_stack;

    std::string::const_iterator it  = aInfixExpression.begin();
    std::string::const_iterator end = aInfixExpression.end();

    while (it != end)
    {
        if ( aOperations.find(*it) != std::string::npos )
        {
            // check precedences
            while (!op_stack.empty() &&
                    aOperations.find(op_stack.top()) != std::string::npos &&
                    cmpprecedence(op_stack.top(), *it) >= 0)
            {
                aResultPostfixExpression << op_stack.top() << " ";
                op_stack.pop();
            }
            op_stack.push(*it);
        }
        else if ( *it == '(' )
            op_stack.push( *it );
        else if ( *it == ')' )
        {
            while (!op_stack.empty() &&
                    op_stack.top() != '(')
            {
                aResultPostfixExpression << op_stack.top() << " ";
                op_stack.pop();
            }
            op_stack.pop();
        }
        else aResultPostfixExpression << *it << " ";
        ++it;
    }

    while (!op_stack.empty())
    {
        aResultPostfixExpression << op_stack.top() << " ";
        op_stack.pop();
    }
}

/// @deprecated
int Factory::eval( std::istream & infix,  const std::string & ops  )
{
    std::stack<int> args;
    std::string token;

    while (infix >> token)
    {
        std::cout << "token: " << token << std::endl;
        if (ops.find(token) != std::string::npos)
        {
            int tmp = args.top();
            args.pop();

            switch (*token.c_str())
            {
                case '+': args.top() += tmp; break;
                case '-': args.top() -= tmp; break;
                case '|': args.top() = args.top() || tmp; break;
                case '*': args.top() *= tmp; break;
                case '/': args.top() /= tmp; break;
                case '^': args.top() ^= tmp; break;
                case '&': args.top() = args.top() && tmp; break;
                case '<': args.top() = args.top() < tmp; break;
                case '>': args.top() = args.top() > tmp; break;
                default: std::cout << "?" << *token.c_str() << "?"; break;
            }
        }
        else
        {
            std::stringstream s( token.c_str() );
            int tmp;
            s >> tmp;
            args.push( tmp /*atoi(token.c_str())*/ );
        }
    }

    if (args.size() != 1)
        throw std::runtime_error("blad w wyrazeniu");

    return args.top();
}

void Factory::transform(
        ExpressionTokensStack & aResultPostfixExpression,
        const std::string & aInfixExpression,
        const std::string & aOperations  )
{
    init_precedencetab();

    std::list< ExpressionTokenPtr>  lExpressionTokensList;
    std::stack<std::string> op_stack;
    std::stringstream lExpressionStream(aInfixExpression);

    Tokenizer lTokenizer;
    std::string lTok = lTokenizer.nextStrToken( lExpressionStream );

    while ( ! lTok.empty() )
    {
        if ( lTok.size() == 1 &&
             aOperations.find(lTok[0]) != std::string::npos )
        {
            // check precedences
            while (!op_stack.empty() &&
                   aOperations.find(op_stack.top()[0]) != std::string::npos &&
                   cmpprecedence(op_stack.top()[0], lTok[0]) >= 0)
            {
                lExpressionTokensList.push_back( createToken( op_stack.top() ) );
                op_stack.pop();
            }
            op_stack.push(lTok);
        }
        else if ( lTok == "(" )
            op_stack.push( lTok );
        else if ( lTok == ")" )
        {
            while (!op_stack.empty() &&
                    op_stack.top() != "(")
            {
                lExpressionTokensList.push_back( createToken( op_stack.top() ) );
                op_stack.pop();
            }
            op_stack.pop();
        }
        else lExpressionTokensList.push_back( createToken( lTok ) );

        lTok = lTokenizer.nextStrToken( lExpressionStream );
    }

    while ( ! op_stack.empty() )
    {
        lExpressionTokensList.push_back( createToken( op_stack.top() ) );

        op_stack.pop();
    }

    while ( ! lExpressionTokensList.empty() )
    {
        aResultPostfixExpression.push( lExpressionTokensList.back() );
        lExpressionTokensList.pop_back();
    }
}



std::string Factory::evalExpression( const std::string & aInfixInput )
{
    ExpressionTokensStack     lStack;
    Factory().transform(lStack, aInfixInput );

    Evaluators::Evaluator lEvaluator;
//    Evaluators::PrintingEvaluator lEvaluator( std::cout );
    Evaluators::evaluate( lStack, lEvaluator );


    if ( ! lEvaluator.getOperandsStack().empty() )
    {
        std::stringstream lFormatter;
        Operands::OperandPtr lOperand = lEvaluator.getOperandsStack().top();
        Evaluators::PrintingEvaluator lResult( lFormatter );
        lOperand->accept( lResult );
        return lFormatter.str();
    }

    return "";
}

std::string Factory::nextStrToken( std::istream & aInput )
{
    std::string lResult;
    return (aInput >> lResult) ? lResult : "";
}

ExpressionTokenPtr Factory::createToken( const std::string & aInput )
{
    ExpressionTokenPtr lResult;

    if ( ! aInput.empty() )
    {
        if ( aInput.size() > 1 )
        {
            lResult = Operands::Numeric::Ptr( new Operands::Numeric( std::stod( aInput ) ) );
        }
        else
        {
            switch ( aInput[0] )
            {
                case '+': lResult = Operations::Add::Ptr( new Operations::Add() ); break;
                case '-': lResult = Operations::Sub::Ptr( new Operations::Sub() ); break;
                case '|': lResult = Operations::Or::Ptr( new Operations::Or() ); break;
                case '*': lResult = Operations::Mul::Ptr( new Operations::Mul() ); break;
                case '/': lResult = Operations::Div::Ptr( new Operations::Div() ); break;
                case '^': lResult = Operations::Pow::Ptr( new Operations::Pow() ); break;
                case '&': lResult = Operations::And::Ptr( new Operations::And() ); break;
                case '<': lResult = Operations::Lt::Ptr( new Operations::Lt() ); break;
                case '>': lResult = Operations::Gt::Ptr( new Operations::Gt() ); break;
                default:
                    {
                        try
                        {
                            lResult = Operands::Numeric::Ptr( new Operands::Numeric( std::stod( aInput ) ) );
                        }
                        catch ( std::invalid_argument & e )
                        {
                            lResult = Operands::Text::Ptr( new Operands::Text( aInput ) );
                        }
                    }
                break;
            }
        }
    }

    return lResult;
}

ExpressionTokenPtr Factory::createToken( const char aInput )
{
    return createToken( std::string(1, aInput) );
}



void Factory::init_precedencetab()
{
    // +, -, *, /, ^
    precedencetab['<'] = 0;
    precedencetab['>'] = 0;
    precedencetab['+'] = 1;
    precedencetab['-'] = 2;
    precedencetab['|'] = 2;
    precedencetab['*'] = 3;
    precedencetab['/'] = 3;
    precedencetab['^'] = 3;
    precedencetab['&'] = 3;
}
