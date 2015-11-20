
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


template < typename ArgType, typename OperationType >
bool Evaluator::invokeEval( OperationType & aOperation, Operands::OperandPtr aArg )
{
    if ( typename ArgType::Ptr lArg = dynamic_pointer_cast< ArgType >( aArg ) )
    {
        iOperands.push( aOperation.eval( lArg ) );
        return true;
    }

    return false;
}

template < typename LhsType, typename RhsType, typename OperationType >
bool Evaluator::invokeEval( OperationType & aOperation, Operands::OperandPtr aLhs, Operands::OperandPtr aRhs )
{
    if ( typename LhsType::Ptr lL = std::dynamic_pointer_cast<LhsType>( aLhs ) )
    {
        if ( typename RhsType::Ptr lR = std::dynamic_pointer_cast<RhsType>( aRhs ) )
        {
            iOperands.push( aOperation.eval( lL, lR ) );
            return true;
        }
    }

    return false;
}

void Evaluator::visit( Operands::BoolPtr aOperand )
{
    iOperands.push( aOperand );
}

void Evaluator::visit( Operands::NumericPtr aOperand )
{
    iOperands.push( aOperand );
}

void Evaluator::visit( Operands::TextPtr aOperand )
{
    iOperands.push( aOperand );
}

void Evaluator::visit( Operations::Add & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Add ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
    {
        if ( ! invokeEval< Text, Text >( aOperation, lLhs, lRhs ) )
        {
            throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
        }
    }
}



void Evaluator::visit( Operations::Sub & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Sub ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
    {
        throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Mul & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Mul ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
    {
        throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Div & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Div ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
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
}


void Evaluator::visit( Operations::Eq &  aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Eq ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
    {
        if ( ! invokeEval< Text, Text >( aOperation, lLhs, lRhs ) )
        {
            if ( ! invokeEval< Bool, Bool >( aOperation, lLhs, lRhs ) )
            {
                throw std::invalid_argument("Evaluator::execute( Add ) can't handle arguments of such type.");
            }
        }
    }
}

void Evaluator::visit( Operations::Neq & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Neq ) too few args on the stack.");
    }

}

void Evaluator::visit( Operations::And & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( And ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Bool, Bool >( aOperation, lLhs, lRhs ) )
    {
        throw std::invalid_argument("Evaluator::execute( Or ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Or & aOperation )
{
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Or ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Bool, Bool >( aOperation, lLhs, lRhs ) )
    {
        throw std::invalid_argument("Evaluator::execute( Or ) can't handle arguments of such type.");
    }
}

void Evaluator::visit( Operations::Not & aOperation )
{
    if ( iOperands.size() < 1 )
    {
        throw std::runtime_error("Evaluator::execute( Not ) too few args on the stack.");
    }

    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Bool >( aOperation, lLhs ) )
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

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
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

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
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

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
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

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
    iOperands.pop();

    if ( ! invokeEval< Numeric, Numeric >( aOperation, lLhs, lRhs ) )
    {
        throw std::invalid_argument("Evaluator::execute( Le ) can't handle arguments of such type.");
    }
}



} // namespace Evaluators
