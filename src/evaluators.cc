
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
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Sub ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
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
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Mul ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
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
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Div ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
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
    if ( iOperands.size() < 2 )
    {
        throw std::runtime_error("Evaluator::execute( Or ) too few args on the stack.");
    }

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
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

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
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

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
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

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
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

    OperandPtr lRhs = iOperands.top();
    iOperands.pop();
    OperandPtr lLhs = iOperands.top();
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


void PrintingEvaluator::visit( Operands::BoolPtr         aOperand )
{
    PrintingEvaluator::handleOperandVisit<>( aOperand );
}

void PrintingEvaluator::visit( Operands::NumericPtr      aOperand )
{
    PrintingEvaluator::handleOperandVisit<>( aOperand );
}

void PrintingEvaluator::visit( Operands::TextPtr         aOperand )
{
    PrintingEvaluator::handleOperandVisit<>( aOperand );
}

void PrintingEvaluator::visit( Operations::Add & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Sub & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Mul & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Div & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Pow & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Eq  & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Neq & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::And & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Or  & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Not & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Gt  & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Ge  & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Lt  & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}

void PrintingEvaluator::visit( Operations::Le  & aOperation )
{
    PrintingEvaluator::handleOperationVisit<>( aOperation );
}


} // namespace Evaluators
