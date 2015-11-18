#include "TestTokenizer.hh"

#include <Tokenizer.hh>

#include <sstream>
#include <iostream>
#include <cstring>
#include <tuple>


TEST_P(TestTokenizer, nextToken)
{
    static const char *lDelim = " :\t\n\r";

    std::stringstream lInput( std::get< 0 >( GetParam() ) );
    std::string       lTokensString( std::get< 1 >( GetParam() ) );
    char lTokens[ std::get< 1 >( GetParam() ).size() ];

    std::copy( lTokensString.begin(), lTokensString.end(), lTokens );
    lTokens[lTokensString.size()] = 0;

    std::string lTokenActual;
    Tokenizer lTokenizer;
    char *lTokenExpected = std::strtok( lTokens, lDelim);
    while ( lTokenExpected )
    {
        lTokenActual = lTokenizer.nextStrToken( lInput );

//        std::cout << "lInput: " << lInput.str() << ", nextToken: " << lTokenActual << std::endl;

        ASSERT_EQ( lTokenExpected, lTokenActual ) << "lInput: " << lInput.str() ;

        lTokenExpected = std::strtok( NULL, lDelim);
    }

    lTokenActual = lTokenizer.nextStrToken( lInput );
    ASSERT_TRUE( lTokenActual.empty() ) << lTokenActual;
}

static std::tuple< std::string, std::string > lPlusOrMinusAndSign[] = {
    std::make_tuple( "1++1", "1:+:+1" ),
    std::make_tuple( "1+-1", "1:+:-1" ),
    std::make_tuple( "2--2", "2:-:-2" ),
    std::make_tuple( "2-+2", "2:-:+2" ),
};

static std::tuple< std::string, std::string > lSingleCharacter[] = {
    std::make_tuple( "1", "1" ),
    std::make_tuple( "a", "a" ),
    std::make_tuple( "B", "B" ),
    std::make_tuple( "+", "+" ),
    std::make_tuple( "-", "-" ),
    std::make_tuple( "*", "*" ),
    std::make_tuple( "^", "^" ),
    std::make_tuple( "/", "/" ),
    std::make_tuple( "(", "(" ),
    std::make_tuple( ")", ")" ),
    std::make_tuple( "&", "&" ),
    std::make_tuple( "|", "|" ),
};

static std::tuple< std::string, std::string > lVaria[] = {
    std::make_tuple( "1+", "1:+" ),
    std::make_tuple( "2-", "2:-" ),
    std::make_tuple( "3*", "3:*" ),
    std::make_tuple( "4^", "4:^" ),
    std::make_tuple( "5/", "5:/" ),
    std::make_tuple( "6(", "6:(" ),
    std::make_tuple( "7)", "7:)" ),
    std::make_tuple( "8&", "8:&" ),
    std::make_tuple( "9|", "9:|" ),

    std::make_tuple( "+1", "+1" ),
    std::make_tuple( "-2", "-2" ),
    std::make_tuple( "*3", "*:3" ),
    std::make_tuple( "^4", "^:4" ),
    std::make_tuple( "/5", "/:5" ),
    std::make_tuple( "(6", "(:6" ),
    std::make_tuple( ")7", "):7" ),
    std::make_tuple( "&8", "&:8" ),
    std::make_tuple( "|9", "|:9" ),

    std::make_tuple( "1+1", "1:+:1" ),
    std::make_tuple( "2-2", "2:-:2" ),
    std::make_tuple( "3*3", "3:*:3" ),
    std::make_tuple( "4^4", "4:^:4" ),
    std::make_tuple( "5/5", "5:/:5" ),
    std::make_tuple( "6(6", "6:(:6" ),
    std::make_tuple( "7)7", "7:):7" ),
    std::make_tuple( "8&8", "8:&:8" ),
    std::make_tuple( "9|9", "9:|:9" ),

    std::make_tuple( "1.09991 + 1.1 + 2 4.19991", "1.09991:+:1.1:+:2:4.19991" ),
};

class ReadTests
{
public:
    typedef std::tuple< std::string, std::string > InputOutputPair;
    typedef std::vector< InputOutputPair > TestDataContainer;

public:
    ReadTests( const std::string & aFilePath )
        : iFilePath( aFilePath )
    {
    }

    const TestDataContainer & getTestData() const
    {
        return iTestData;
    }
private:
    std::string iFilePath;
    TestDataContainer iTestData;
};

ReadTests aVaria2( "" );

INSTANTIATE_TEST_CASE_P(Plus_or_minus_and_sign, TestTokenizer, ::testing::ValuesIn( lPlusOrMinusAndSign ) );
INSTANTIATE_TEST_CASE_P(Single_character, TestTokenizer, ::testing::ValuesIn( lSingleCharacter ) );
INSTANTIATE_TEST_CASE_P(Varia, TestTokenizer, ::testing::ValuesIn( lVaria ) );
INSTANTIATE_TEST_CASE_P(Varia2, TestTokenizer, ::testing::ValuesIn( aVaria2.getTestData() ) );
