#pragma once

#include <string>
#include <iosfwd>
#include <sstream>

#include "exprtoken.hh"

class Tokenizer
{
public:
    std::string nextStrToken( std::istream & aInput )
    {
        static const char * lDigits = "0123456789";
        static const char   lDecPoint = '.';
        static const std::string   lSigns = "+-*/^()&|";

        std::string lResult;

        if ( iBuffer.empty() )
        {
            aInput >> iBuffer;
        }

        if ( ! iBuffer.empty() )
        {
            if (std::isdigit( iBuffer[0] ))
            {
                std::string::size_type lPos = iBuffer.find_first_not_of(lDigits);
                if (lPos != std::string::npos && iBuffer[lPos] == lDecPoint)
                {
                    lPos = iBuffer.find_first_not_of(lDigits, lPos+1);
                }
                lResult = iBuffer.substr( 0, lPos );
                iBuffer.erase( 0, lPos );
            }
            else if ( lSigns.find( iBuffer[0] ) != std::string::npos )
            {
                lResult = iBuffer[0];
                iBuffer.erase(0, 1);
            }
        }

        return lResult;
    }

private:
    std::string iBuffer;
};

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
    void init_precedencetab();

    inline int cmpprecedence( const char op1, const char op2 )
    {
        return precedencetab[op1] - precedencetab[op2];
    }

private:
    int precedencetab['^'+1];
};

