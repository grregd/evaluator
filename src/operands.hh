#ifndef __OPERANDS_HH__
#define __OPERANDS_HH__

#include <memory>
#include <stack>
#include <string>

#include "exprtoken.hh"

// fwd decl
namespace Evaluators
{
class Visitor;
} // namespace Evaluators


namespace Operands
{

typedef double NumericType;

class Operand: public ExpressionToken
{
};

/**
 * @brief Represents the operand which selects its value from Subject.
 */
class SelectorFP11
    : public Operand
    , public std::enable_shared_from_this< SelectorFP11 >
{
public:
    typedef std::shared_ptr< SelectorFP11 > Ptr;

public:
    void setSubject() {}

public:
    void accept( Evaluators::Visitor & );

private:
    //FP11 iSubject;
};

/**
 * class Bool
 */
class Bool
   : public Operand
   , public std::enable_shared_from_this< Bool >
{
public:
    typedef std::shared_ptr< Bool > Ptr;

public:
    Bool(): iValue(0)
    {}

    Bool( bool aValue ): iValue( aValue )
    {}

public:
    bool getValue() const { return iValue; }
    void setValue( bool aValue ) { iValue = aValue; }

public:
    void accept( Evaluators::Visitor & );

private:
    bool iValue;
};

/**
 * class Numeric
 */
class Numeric
    : public Operand
    , public std::enable_shared_from_this< Numeric >
{
public:
    typedef std::shared_ptr< Numeric > Ptr;

public:
    Numeric(): iValue(0)
    {}

    Numeric( NumericType aValue ): iValue( aValue )
    {}

public:
    NumericType getValue() const { return iValue; }
    void setValue( NumericType aValue ) { iValue = aValue; }

public:
    void accept( Evaluators::Visitor & );

private:
    NumericType iValue;
};

/**
 * class Text
 */
class Text
    : public Operand
    , public std::enable_shared_from_this< Text >
{
public:
    typedef std::shared_ptr< Text > Ptr;

public:
    Text()
    {}

    Text( const std::string & aValue ): iValue( aValue )
    {}

public:
    const std::string & getValue() const { return iValue; }
    void setValue( const std::string & aValue ) { iValue = aValue; }

public:
    void accept( Evaluators::Visitor & );

private:
    std::string iValue;
};


typedef std::shared_ptr< Operand >       OperandPtr;
typedef std::shared_ptr< SelectorFP11 >  SelectorFP11Ptr;
typedef std::shared_ptr< Bool >          BoolPtr;
typedef std::shared_ptr< Numeric >       NumericPtr;
typedef std::shared_ptr< Text >          TextPtr;

typedef std::stack< OperandPtr >              OperandsStack;


} // namespace Operands

#endif // __OPERANDS_HH__
