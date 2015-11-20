#include "PrintingEvaluator.hh"
#include "operations.hh"
#include "operands.hh"


namespace Evaluators
{

void PrintingEvaluator::visit( Operands::BoolPtr aOperand )
{
    PrintingEvaluator::handleOperandVisit<>( aOperand );
}

void PrintingEvaluator::visit( Operands::NumericPtr aOperand )
{
    PrintingEvaluator::handleOperandVisit<>( aOperand );
}

void PrintingEvaluator::visit( Operands::TextPtr aOperand )
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

}

