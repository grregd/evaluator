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
    template < typename ArgType, typename OperationType >
    bool invokeEval( OperationType & aOperation, Operands::OperandPtr aArg );

    template < typename LhsType, typename RhsType, typename OperationType >
    bool invokeEval( OperationType & aOperation, Operands::OperandPtr aLhs, Operands::OperandPtr aRhs );

private:
    Operands::OperandsStack iOperands;
};


} // namespace Evaluators


#endif // __EVALUATORS_HH__
