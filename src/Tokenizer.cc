
#include "Tokenizer.hh"

#include <algorithm>
#include <stdexcept>
#include <functional>
#include <functional>


Tokenizer::Tokenizer()
{
}

Tokenizer::~Tokenizer()
{
}

std::string Tokenizer::nextStrToken( std::istream & aInput )
{
    std::string lResult;

    if ( iBuffer.empty() )
    {
        aInput >> iBuffer;
    }

    if ( ! iBuffer.empty() )
    {
        if ( isPlusOrMinus( cc() ) )
        {
            if ( iPreviousToken.empty() &&
                 l() > 0 && isDigit( nc() ) )
            {
                eatNumber( lResult );
            }
            else if (isPlusOrMinus(iPreviousToken[0]))
            {
                eatOperator( lResult );
                iPreviousToken = lResult;
                lResult += nextStrToken( aInput );
            }
            else
            {
                eatOperator( lResult );
            }
        }
        else if ( isOperator( cc() ) )
        {
            eatOperator( lResult );
        }
        else if ( isDigit( cc() ) )
        {
            eatNumber( lResult );
        }
        else if ( isAlpha( cc() ) )
        {
            eatName( lResult );
        }
        else
        {
            throw std::runtime_error("unrecognized input");
        }
    }

    return iPreviousToken = lResult;
}

void Tokenizer::eatName( std::string & aResult )
{
    std::string::iterator lPos
            = std::find_if( iBuffer.begin(), iBuffer.end(), std::bind(
                                std::not1( std::bind1st( std::mem_fun(
                                    &Tokenizer::isAlpha ), this ) ),
                                    std::placeholders::_1 ) );

    aResult.append( iBuffer.begin(), lPos );
    iBuffer.erase( iBuffer.begin(), lPos );
}

void Tokenizer::eatNumber( std::string & aResult )
{
    static const char * lDigits   = "0123456789";
    static const char   lDecPoint = '.';

    std::string::size_type lPos = 0;

    if ( isDigit( cc() ) ||
         l() > 1 && isPlusOrMinus( cc() ) && isDigit( nc() ) )
    {
         lPos = 1;
    }
    else
    {
        throw std::runtime_error( "eatNumber: this is not a number" );
    }

    lPos = iBuffer.find_first_not_of(lDigits, lPos);
    if (lPos != std::string::npos && iBuffer[lPos] == lDecPoint)
    {
        lPos = iBuffer.find_first_not_of(lDigits, lPos+1);
    }
    aResult = iBuffer.substr( 0, lPos );
    iBuffer.erase( 0, lPos );
}

void Tokenizer::eatOperator( std::string & aResult )
{
    aResult = cc();
    iBuffer.erase(0, 1);
}

bool Tokenizer::isAlpha( const char aChar ) const
{
    return std::isalpha( aChar );
}

bool Tokenizer::isDigit( const char aChar ) const
{
    return std::isdigit( aChar );
}

bool Tokenizer::isOperator( const char aChar ) const
{
    static const std::string lSigns("+-*/^()&|");

    return std::string::npos != lSigns.find( aChar );
}

bool Tokenizer::isPlusOrMinus( const char aChar ) const
{
    static const std::string lPlusMinus("+-");

    return std::string::npos != lPlusMinus.find( aChar );
}

