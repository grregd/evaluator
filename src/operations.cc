
#include <iostream>
#include <stdexcept>

#include "evaluators.hh"
#include "operations.hh"

namespace Operations
{
using namespace std;
using namespace Evaluators;

// class Add
void Add::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::NumericPtr Add::eval( const Operands::NumericPtr & aLhs,
                                const Operands::NumericPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::NumericPtr(
        new Operands::Numeric(
              aLhs->getValue()
            + aRhs->getValue() ) );
}

Operands::TextPtr Add::eval( const Operands::TextPtr & aLhs,
                             const Operands::TextPtr & aRhs  )
{
//    cout << __PRETTY_FUNCTION__ << endl;

    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

//    cout << "arg1: " << aLhs->getValue() << endl;
//    cout << "arg2: " << aRhs->getValue() << endl;

    return Operands::TextPtr(
        new Operands::Text(
              aLhs->getValue()
            + aRhs->getValue() ) );
}

// class Sub
void Sub::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::NumericPtr Sub::eval( const Operands::NumericPtr & aLhs,
                                const Operands::NumericPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::NumericPtr(
        new Operands::Numeric(
              aLhs->getValue()
            - aRhs->getValue() ) );
}


// class Mul
void Mul::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::NumericPtr Mul::eval( const Operands::NumericPtr & aLhs,
                                const Operands::NumericPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::NumericPtr(
        new Operands::Numeric(
              aLhs->getValue()
            * aRhs->getValue() ) );
}

// class Div
void Div::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::NumericPtr Div::eval( const Operands::NumericPtr & aLhs,
                                const Operands::NumericPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    if ( aRhs->getValue() == 0 )
    {
        throw invalid_argument("Division by 0.");
    }

    return Operands::NumericPtr(
        new Operands::Numeric(
              aLhs->getValue()
            / aRhs->getValue() ) );
}

// class Pow
void Pow::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

// class Eq
void Eq::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

// class Neq
void Neq::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

// class Or
void Or::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::BoolPtr Or::eval( const Operands::BoolPtr & aLhs,
                            const Operands::BoolPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::BoolPtr(
        new Operands::Bool(
               aLhs->getValue()
            || aRhs->getValue() ) );
}


// class And
void And::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::BoolPtr And::eval( const Operands::BoolPtr & aLhs,
                            const Operands::BoolPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::BoolPtr(
        new Operands::Bool(
               aLhs->getValue()
            && aRhs->getValue() ) );
}


// class Not
void Not::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::OperandPtr Not::eval( const Operands::BoolPtr & aArg )
{
    cout << __PRETTY_FUNCTION__ << endl;

    if ( ! aArg )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::BoolPtr(
        new Operands::Bool(
              ! aArg->getValue() ) );
}

// class Gt
void Gt::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::BoolPtr Gt::eval( const Operands::NumericPtr & aLhs,
                            const Operands::NumericPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::BoolPtr(
        new Operands::Bool(
               aLhs->getValue()
            > aRhs->getValue() ) );
}


// class Ge
void Ge::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::BoolPtr Ge::eval( const Operands::NumericPtr & aLhs,
                            const Operands::NumericPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::BoolPtr(
        new Operands::Bool(
               aLhs->getValue()
            >= aRhs->getValue() ) );
}


// class Lt
void Lt::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::BoolPtr Lt::eval( const Operands::NumericPtr & aLhs,
                            const Operands::NumericPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::BoolPtr(
        new Operands::Bool(
               aLhs->getValue()
            < aRhs->getValue() ) );
}



// class Le
void Le::accept( Visitor & aEvaluator )
{
    aEvaluator.visit( *this );
}

Operands::BoolPtr Le::eval( const Operands::NumericPtr & aLhs,
                            const Operands::NumericPtr & aRhs  )
{
    if ( ! aLhs || ! aRhs )
    {
        throw invalid_argument("Null pointer.");
    }

    return Operands::BoolPtr(
        new Operands::Bool(
               aLhs->getValue()
            <= aRhs->getValue() ) );
}



} // namespace Operations
