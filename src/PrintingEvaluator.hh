#pragma once

#include <iostream>
#include "evaluators.hh"

namespace Evaluators
{

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



}
