#ifndef __EVALUATORS_HH__
#define __EVALUATORS_HH__

#include <stdexcept>

#include "operands.hh"
#include "exprtoken.hh"

// fwd declarations
namespace Operations
{
class Add;
class Sub;
class Mul;
class Div;
class Pow;
class Eq;
class Neq;
class Or;
class And;
class Not;
class Gt;
class Ge;
class Lt;
class Le;
} // namespace Operations



namespace Evaluators
{


/**
 * class Evaluator
 */
class Evaluator
{
public:
    Evaluator( )  {}

    void eval( ExpressionTokensStack & );
    const Operands::OperandsStack & getOperandsStack() const { return iOperands; }

public:
    void visit( Operands::SelectorFP11Ptr aOperand );
    void visit( Operands::BoolPtr         aOperand );
    void visit( Operands::NumericPtr      aOperand );
    void visit( Operands::TextPtr         aOperand );

public:
    void visit( Operations::Add & aOperation );
    void visit( Operations::Sub & aOperation );
    void visit( Operations::Mul & aOperation );
    void visit( Operations::Div & aOperation );
    void visit( Operations::Pow & aOperation );

    void visit( Operations::Eq  & aOperation );
    void visit( Operations::Neq & aOperation );
    void visit( Operations::And & aOperation );
    void visit( Operations::Or  & aOperation );
    void visit( Operations::Not & aOperation );
    void visit( Operations::Gt  & aOperation );
    void visit( Operations::Ge  & aOperation );
    void visit( Operations::Lt  & aOperation );
    void visit( Operations::Le  & aOperation );

private:
//    template< typename Operation >
//    Operands::OperandPtr dispatchOneArg( Operation & aOp, const Operands::OperandPtr & aArg ) //throw std::invalid_argument
//    {
//        if ( Operands::NumericPtr lNumeric = std::dynamic_pointer_cast<Operands::Numeric>( aArg ) )
//        {
//            return aOp.eval( lNumeric );
//        }
//        else
//        {
//            throw std::invalid_argument( std::string("Evaluator::execute( ") + std::string(typeid(aOp).name()) + " ) can't handle argument.");
//        }
//    }

private:
    Operands::OperandsStack iOperands;
};


} // namespace Evaluators


#endif // __EVALUATORS_HH__
