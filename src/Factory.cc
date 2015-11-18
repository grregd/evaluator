
#include "Factory.hh"
#include "evaluators.hh"
#include "operands.hh"
#include "operations.hh"

#include <iostream>
#include <stdexcept>
#include <list>
#include <stack>




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

    std::string lTok = Factory::nextStrToken( lExpressionStream );

    while ( ! lTok.empty() )
    {
        if ( aOperations.find(lTok[0]) != std::string::npos )
        {
            // check precedences
            while (!op_stack.empty() &&
                   aOperations.find(op_stack.top()[0]) != std::string::npos &&
                   cmpprecedence(op_stack.top()[0], lTok[0]) >= 0)
            {
//                    aResultPostfixExpression.push( createToken( op_stack.top() ) );
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
//                    aResultPostfixExpression.push( createToken( op_stack.top() ) );
                lExpressionTokensList.push_back( createToken( op_stack.top() ) );
                op_stack.pop();
            }
            op_stack.pop();
        }
//            else aResultPostfixExpression.push( createToken( lTok ) );
        else lExpressionTokensList.push_back( createToken( lTok ) );

        lTok = Factory::nextStrToken( lExpressionStream );
    }

    while (!op_stack.empty())
    {
//            aResultPostfixExpression.push( createToken( op_stack.top() ) );
        lExpressionTokensList.push_back( createToken( op_stack.top() ) );

        op_stack.pop();
    }

    while (! lExpressionTokensList.empty())
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
    lEvaluator.eval( lStack );

    std::stringstream lFormatter;

    if ( ! lEvaluator.getOperandsStack().empty() )
    {
        Operands::OperandPtr lOperand = lEvaluator.getOperandsStack().top();
        if ( Operands::Numeric::Ptr lValue = std::dynamic_pointer_cast< Operands::Numeric >( lOperand ) )
        {
            lFormatter << lValue->getValue();
        }
        else if ( Operands::Bool::Ptr lValue = std::dynamic_pointer_cast< Operands::Bool >( lOperand ) )
        {
            lFormatter << std::boolalpha << lValue->getValue();
        }
        else if ( Operands::Text::Ptr lValue = std::dynamic_pointer_cast< Operands::Text >( lOperand ) )
        {
            return lValue->getValue();
        }
        else if ( Operations::Operation::Ptr lValue = std::dynamic_pointer_cast< Operations::Operation >( lOperand ) )
        {
            lFormatter << typeid(lValue).name();
        }
    }

    return lFormatter.str();
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
                    std::stringstream s( aInput );
                    double lValue;
                    s >> lValue;

                    lResult = Operands::Numeric::Ptr( new Operands::Numeric(lValue) );
                }
            break;
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
