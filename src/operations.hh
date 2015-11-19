#ifndef __OPERATIONS_HH__
#define __OPERATIONS_HH__

#include <memory>
#include <stdexcept>
#include <stack>
#include <iostream>

#include "exprtoken.hh"
#include "operands.hh"

namespace Evaluators
{
class Visitor;
}


namespace Operations
{

using Evaluators::Visitor;

/**
 * class Operation
 */
class Operation: public ExpressionToken
{
public:
    typedef std::shared_ptr< Operation > Ptr;

public:
    virtual ~Operation() {}
};


/**
 * class Add
 */
class Add: public Operation
{
public:
    typedef std::shared_ptr< Add > Ptr;

public:
    void accept( Visitor & aEvaluator );

public:
    Operands::NumericPtr eval( const Operands::NumericPtr & aLhs,
                               const Operands::NumericPtr & aRhs  );

    Operands::TextPtr eval( const Operands::TextPtr & aLhs,
                            const Operands::TextPtr & aRhs  );
};


/**
 * class Sub
 */
class Sub: public Operation
{
public:
    typedef std::shared_ptr< Sub > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::NumericPtr eval( const Operands::NumericPtr & aLhs,
                               const Operands::NumericPtr & aRhs  );
};


/**
 * class Mul
 */
class Mul: public Operation
{
public:
    typedef std::shared_ptr< Mul > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::NumericPtr eval( const Operands::NumericPtr & aLhs,
                               const Operands::NumericPtr & aRhs  );
};


/**
 * class Div
 */
class Div: public Operation
{
public:
    typedef std::shared_ptr< Div > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::NumericPtr eval( const Operands::NumericPtr & aLhs,
                               const Operands::NumericPtr & aRhs  );
};


/**
 * class Pow
 */
class Pow: public Operation
{
public:
    typedef std::shared_ptr< Pow > Ptr;

public:
    void accept( Visitor & );
};


/**
 * class Eq
 */
class Eq: public Operation
{
public:
    typedef std::shared_ptr< Eq > Ptr;

public:
    void accept( Visitor & );

    template< typename PtrType >
    Operands::BoolPtr eval( const PtrType & aLhs,
                            const PtrType & aRhs )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        if ( ! aLhs || ! aRhs )
        {
            throw std::invalid_argument("Null pointer.");
        }

        return Operands::BoolPtr(
            new Operands::Bool(
                aLhs->getValue() == aRhs->getValue() ) );
    }
};

/**
 * class Neq
*/
class Neq: public Operation
{
public:
    typedef std::shared_ptr< Neq > Ptr;

public:
    void accept( Visitor & );
};

/**
 * class And
 */
class And: public Operation
{
public:
    typedef std::shared_ptr< And > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::BoolPtr eval( const Operands::BoolPtr & aLhs,
                            const Operands::BoolPtr & aRhs  );
};

/**
 * class Or
 */
class Or: public Operation
{
public:
    typedef std::shared_ptr< Or > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::BoolPtr eval( const Operands::BoolPtr & aLhs,
                            const Operands::BoolPtr & aRhs  );
};

/**
 * class Not
 */
class Not: public Operation
{
public:
    typedef std::shared_ptr< Not > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::OperandPtr eval( const Operands::BoolPtr & aArg );
};

/**
 * class Gt
 * Implements 'greater than' operation
 */
class Gt: public Operation
{
public:
    typedef std::shared_ptr< Gt > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::BoolPtr eval( const Operands::NumericPtr & aLhs,
                            const Operands::NumericPtr & aRhs );
};

/**
 * class Ge
 * Implements 'greater or equal' operation
 */
class Ge: public Operation
{
public:
    typedef std::shared_ptr< Ge > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::BoolPtr eval( const Operands::NumericPtr & aLhs,
                            const Operands::NumericPtr & aRhs );
};

/**
 * class Lt
 * Implements 'less than' operation
 */
class Lt: public Operation
{
public:
    typedef std::shared_ptr< Lt > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::BoolPtr eval( const Operands::NumericPtr & aLhs,
                            const Operands::NumericPtr & aRhs );
};

/**
 * class Le
 * Implements 'less or equal' operation
 */
class Le: public Operation
{
public:
    typedef std::shared_ptr< Le > Ptr;

public:
    void accept( Visitor & );

public:
    Operands::BoolPtr eval( const Operands::NumericPtr & aLhs,
                            const Operands::NumericPtr & aRhs );
};


//typedef std::shared_ptr<Add> AddPtr;
//typedef std::shared_ptr<Sub> SubPtr;
//typedef std::shared_ptr<Mul> MulPtr;
//typedef std::shared_ptr<Div> DivPtr;
//typedef std::shared_ptr<Pow> PowPtr;

//typedef std::shared_ptr<Eq>  EqPtr;
//typedef std::shared_ptr<Neq> NeqPtr;
//typedef std::shared_ptr<Or>  OrPtr;
//typedef std::shared_ptr<And> AndPtr;
//typedef std::shared_ptr<Not> NotPtr;
} // namespace Operations

#endif // __OPERATIONS_HH__
