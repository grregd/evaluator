#ifndef __EVALUATORS_HH__
#define __EVALUATORS_HH__

#include <stdexcept>
#include <iostream>

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

void evaluate( ExpressionTokensStack & aStack, Visitor & aEvaluator );

class Visitor
{
public:
    virtual ~Visitor() {}

    virtual void visit( Operands::BoolPtr    aOperand ) = 0;
    virtual void visit( Operands::NumericPtr aOperand ) = 0;
    virtual void visit( Operands::TextPtr    aOperand ) = 0;

public:
    virtual void visit( Operations::Add & aOperation ) = 0;
    virtual void visit( Operations::Sub & aOperation ) = 0;
    virtual void visit( Operations::Mul & aOperation ) = 0;
    virtual void visit( Operations::Div & aOperation ) = 0;
    virtual void visit( Operations::Pow & aOperation ) = 0;

    virtual void visit( Operations::Eq  & aOperation ) = 0;
    virtual void visit( Operations::Neq & aOperation ) = 0;
    virtual void visit( Operations::And & aOperation ) = 0;
    virtual void visit( Operations::Or  & aOperation ) = 0;
    virtual void visit( Operations::Not & aOperation ) = 0;
    virtual void visit( Operations::Gt  & aOperation ) = 0;
    virtual void visit( Operations::Ge  & aOperation ) = 0;
    virtual void visit( Operations::Lt  & aOperation ) = 0;
    virtual void visit( Operations::Le  & aOperation ) = 0;
};


/**
 * class Evaluator
 */
class Evaluator: public Visitor
{
public:
    Evaluator( )  {}

    const Operands::OperandsStack & getOperandsStack() const { return iOperands; }

public:
    void visit( Operands::BoolPtr    aOperand );
    void visit( Operands::NumericPtr aOperand );
    void visit( Operands::TextPtr    aOperand );

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

class PrintingEvaluator: public Visitor
{
public:
    const Operands::OperandsStack & getOperandsStack() const { return iEvaluator.getOperandsStack(); }

    template < typename OStream, typename ArgType >
    OStream & printOperand( OStream & aOStream, ArgType aArg )
    {
        return aOStream << aArg->getValue();
    }

    template < typename OStream, typename ArgType >
    OStream & printOperation( OStream & aOStream, ArgType aArg )
    {
        return aOStream;
    }

    template< typename ArgType >
    void handleOperandVisit( ArgType aArg )
    {
        std::cout << getArgTypeString( __PRETTY_FUNCTION__ ) << ": ";
        printOperand( std::cout, aArg ) << std::endl;
        iEvaluator.visit( aArg );
    }

    template< typename ArgType >
    void handleOperationVisit( ArgType aArg )
    {
        std::cout << getArgTypeString( __PRETTY_FUNCTION__ ) << ": ";
        printOperation( std::cout, aArg ) << std::endl;
        iEvaluator.visit( aArg );
    }

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
    std::string getArgTypeString( const std::string & aPrettyFunction ) const
    {
        return aPrettyFunction.substr( aPrettyFunction.find(" = ")+3 );
    }

private:
    Evaluator iEvaluator;
};


} // namespace Evaluators


#endif // __EVALUATORS_HH__
