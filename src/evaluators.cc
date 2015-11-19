
#include <iostream>
#include <memory>

#include "evaluators.hh"
#include "operations.hh"
#include "operands.hh"
#include "staticdispatcher.hh"

using namespace std;
using namespace Operands;
using namespace Operations;

namespace Evaluators
{

void evaluate( ExpressionTokensStack & aStack, Visitor & aEvaluator )
{
    while ( ! aStack.empty() )
    {
        ExpressionTokenPtr lToken = aStack.top();
        if ( ! lToken )
        {
            throw runtime_error( "Evaluators::evaluate - null pointer on the stack." );
        }
        aStack.pop();
        lToken->accept( aEvaluator );
    }
}

void Evaluator::visit( Operands::SelectorFP11Ptr aOperand )
{
//    cerr << __PRETTY_FUNCTION__ << endl;
    iOperands.push( aOperand );
}

void Evaluator::visit( Operands::BoolPtr aOperand )
{
//    cerr << __PRETTY_FUNCTION__ << endl;
    iOperands.push( aOperand );
}

void Evaluator::visit( Operands::NumericPtr aOperand )
{
//    cerr << __PRETTY_FUNCTION__ << endl;
    iOperands.push( aOperand );
}

void Evaluator::visit( Operands::TextPtr aOperand )
{
//    cerr << __PRETTY_FUNCTION__ << endl;
    iOperands.push( aOperand );
}

void Evaluator::visit( Operations::Add & aOperation )
{
//    cerr << __PRETTY_FUNCTION__ << endl;

    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Add ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else if ( TextPtr lTextL = dynamic_pointer_cast<Text>( lLhs ) )
    {
        if ( TextPtr lTextR = dynamic_pointer_cast<Text>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lTextL, lTextR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
    }
}



void Evaluator::visit( Operations::Sub & aOperation )
{
    //    cerr << __PRETTY_FUNCTION__ << endl;

    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Sub ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Mul & aOperation )
{
    //    cerr << __PRETTY_FUNCTION__ << endl;

    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Mul ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Div & aOperation )
{
    //    cerr << __PRETTY_FUNCTION__ << endl;

    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Div ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Pow & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Pow ) too few args on the stack.");
    }

//    cerr << __PRETTY_FUNCTION__ << endl;
}


void Evaluator::visit( Operations::Eq &  aOperation )
{
//    cerr << __PRETTY_FUNCTION__ << endl;

    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Eq ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else if ( TextPtr lTextL = dynamic_pointer_cast<Text>( lLhs ) )
    {
        if ( TextPtr lTextR = dynamic_pointer_cast<Text>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lTextL, lTextR ) );
        }
    }
    else if ( BoolPtr lBoolL = dynamic_pointer_cast<Bool>( lLhs ) )
    {
        if ( BoolPtr lBoolR = dynamic_pointer_cast<Bool>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lBoolL, lBoolR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Neq & aOperation )
{
    //    cerr << __PRETTY_FUNCTION__ << endl;

    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Neq ) too few args on the stack.");
    }

}

void Evaluator::visit( Operations::And & aOperation )
{
    //    cerr << __PRETTY_FUNCTION__ << endl;

    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( And ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( BoolPtr lBoolL = dynamic_pointer_cast<Bool>( lLhs ) )
    {
        if ( BoolPtr lBoolR = dynamic_pointer_cast<Bool>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lBoolL, lBoolR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Or ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Or & aOperation )
{
    //    cerr << __PRETTY_FUNCTION__ << endl;

    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Or ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( BoolPtr lBoolL = dynamic_pointer_cast<Bool>( lLhs ) )
    {
        if ( BoolPtr lBoolR = dynamic_pointer_cast<Bool>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lBoolL, lBoolR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Or ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Not & aOperation )
{
//    cerr << __PRETTY_FUNCTION__ << endl;
    if ( iOperands.size() < 1 )
    {
        throw std::runtime_error("Evaluator::execute( Not ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

//    dispatchOneArg( aOperation, lLhs );
    //iOperands.push(  );

    if ( BoolPtr lBool = dynamic_pointer_cast< Bool >( lLhs ) )
    {
        iOperands.push( aOperation.eval( lBool ) );
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Not ) can't handle arguments.");
    }
}

void Evaluator::visit( Operations::Gt & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Gt ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Gt ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Ge & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Ge ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Ge ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Lt & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Lt ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Lt ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Le & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Le ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();
    OperandPtr lRhs = iOperands.top();
    iOperands.pop();

    if ( NumericPtr lNumericL = dynamic_pointer_cast<Numeric>( lLhs ) )
    {
        if ( NumericPtr lNumericR = dynamic_pointer_cast<Numeric>( lRhs ) )
        {
            iOperands.push( aOperation.eval( lNumericL, lNumericR ) );
        }
    }
    else
    {
        throw std::invalid_argument("Evaluator::execute( Le ) can't handle arguments of such type.");
    }
}


} // namespace Evaluators
