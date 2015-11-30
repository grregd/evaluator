#pragma once

#include <string>
#include <iosfwd>
#include <sstream>
#include <stdexcept>

#include <exprtoken.hh>

class Factory
{
public:
    static std::string evalExpression( const std::string & aInfixInput );
    static ExpressionTokenPtr createToken( const std::string & aInput );
    static ExpressionTokenPtr createToken( const char aInput );
    static std::string nextStrToken( std::istream & aInput );

    // includes parenthesis
    void transform(
            std::ostream & aResultPostfixExpression,
            const std::string & aInfixExpression,
            const std::string & aOperations = "+-*/^<>|&" );

    /// @deprecated
    int eval( std::istream & infix,  const std::string & ops = "+-*/^<>|&" );

    void transform(
            ExpressionTokensStack & aResultPostfixExpression,
            const std::string & aInfixExpression,
            const std::string & aOperations = "+-*/^<>|&" );

private:
    static void init_precedencetab();

    static inline int cmpprecedence( const char op1, const char op2 )
    {
        return precedencetab[op1] - precedencetab[op2];
    }

private:
    static int precedencetab['^'+1];
    static bool iInit;
};

