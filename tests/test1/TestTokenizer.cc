#include "TestTokenizer.hh"

#include <Factory.hh>

#include <sstream>
#include <iostream>
#include <cstring>


TEST_P(TestTokenizer, nextToken)
{
    static const char *lDelim = " :\t\n\r";

    std::stringstream lInput( std::tr1::get< 0 >( GetParam() ) );
    std::string       lTokensString( std::tr1::get< 1 >( GetParam() ) );
    char lTokens[ std::tr1::get< 1 >( GetParam() ).size() ];

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

static std::tr1::tuple< std::string, std::string > lVaria[] = {
    std::tr1::make_tuple( "1", "1" ),
    std::tr1::make_tuple( "+", "+" ),
    std::tr1::make_tuple( "-", "-" ),
    std::tr1::make_tuple( "*", "*" ),
    std::tr1::make_tuple( "^", "^" ),
    std::tr1::make_tuple( "/", "/" ),
    std::tr1::make_tuple( "(", "(" ),
    std::tr1::make_tuple( ")", ")" ),
    std::tr1::make_tuple( "&", "&" ),
    std::tr1::make_tuple( "|", "|" ),

    std::tr1::make_tuple( "1+", "1:+" ),
    std::tr1::make_tuple( "2-", "2:-" ),
    std::tr1::make_tuple( "3*", "3:*" ),
    std::tr1::make_tuple( "4^", "4:^" ),
    std::tr1::make_tuple( "5/", "5:/" ),
    std::tr1::make_tuple( "6(", "6:(" ),
    std::tr1::make_tuple( "7)", "7:)" ),
    std::tr1::make_tuple( "8&", "8:&" ),
    std::tr1::make_tuple( "9|", "9:|" ),

    std::tr1::make_tuple( "+1", "+1" ),
    std::tr1::make_tuple( "-2", "-2" ),
    std::tr1::make_tuple( "*3", "*:3" ),
    std::tr1::make_tuple( "^4", "^:4" ),
    std::tr1::make_tuple( "/5", "/:5" ),
    std::tr1::make_tuple( "(6", "(:6" ),
    std::tr1::make_tuple( ")7", "):7" ),
    std::tr1::make_tuple( "&8", "&:8" ),
    std::tr1::make_tuple( "|9", "|:9" ),

    std::tr1::make_tuple( "1+1", "1:+:1" ),
    std::tr1::make_tuple( "1++1", "1:+:+1" ),
    std::tr1::make_tuple( "1+-1", "1:+:-1" ),
    std::tr1::make_tuple( "2-2", "2:-:2" ),
    std::tr1::make_tuple( "2--2", "2:-:-2" ),
    std::tr1::make_tuple( "2-+2", "2:-:+2" ),
    std::tr1::make_tuple( "3*3", "3:*:3" ),
    std::tr1::make_tuple( "4^4", "4:^:4" ),
    std::tr1::make_tuple( "5/5", "5:/:5" ),
    std::tr1::make_tuple( "6(6", "6:(:6" ),
    std::tr1::make_tuple( "7)7", "7:):7" ),
    std::tr1::make_tuple( "8&8", "8:&:8" ),
    std::tr1::make_tuple( "9|9", "9:|:9" ),

    std::tr1::make_tuple( "1.09991 + 1.1 + 2 4.19991", "1.09991:+:1.1:+:2:4.19991" ),
};

INSTANTIATE_TEST_CASE_P(Varia, TestTokenizer, ::testing::ValuesIn( lVaria ) );
