#pragma once

#include <string>
#include <iostream>

class Tokenizer
{
public:
    Tokenizer();

    virtual ~Tokenizer();

    std::string nextStrToken( std::istream & aInput );

private:
    void eatName( std::string & aResult );

    void eatNumber( std::string & aResult );

    void eatOperator( std::string & aResult );

    bool isAlpha( const char aChar ) const;

    bool isDigit( const char aChar ) const;

    bool isOperator( const char aChar ) const;

    bool isPlusOrMinus( const char aChar ) const;

    /// Returns current char in buffer
    inline char cc() const
    {
        return iBuffer[0];
    }

    /// Returns next char in buffer
    inline char nc() const
    {
        return iBuffer[1];
    }

    /// Returns length of the buffer.
    inline std::string::size_type l() const
    {
        return iBuffer.size();
    }

private:
    std::string iBuffer;
    std::string iPreviousToken;
};

