#include "TestTokenizer.hh"

#include <Tokenizer.hh>

#include <sstream>
#include <iostream>
#include <cstring>
#include <tuple>


TEST_P(TestTokenizer, nextToken)
{
    std::stringstream lInput( std::get< 0 >( GetParam() ) );

    TokensList lTokensActual;
    Tokenizer lTokenizer;

    for ( std::string lToken = lTokenizer.nextStrToken( lInput );
          ! lToken.empty();
          lToken = lTokenizer.nextStrToken( lInput ) )
    {
        lTokensActual.push_back( lToken );
    }

    ASSERT_EQ( std::get< 1 >( GetParam() ), lTokensActual );
}


static std::tuple< std::string, TokensList > lPlusOrMinusAndSign[] = {
    std::make_tuple( "1++1", TokensList({"1", "+", "+1"}) ),
    std::make_tuple( "1+-1", TokensList({"1", "+", "-1"}) ),
    std::make_tuple( "2--2", TokensList({"2", "-", "-2"}) ),
    std::make_tuple( "2-+2", TokensList({"2", "-", "+2"}) ),

    std::make_tuple( "1+ +1", TokensList({"1", "+", "+1"}) ),
    std::make_tuple( "1+ -1", TokensList({"1", "+", "-1"}) ),
    std::make_tuple( "2- -2", TokensList({"2", "-", "-2"}) ),
    std::make_tuple( "2- +2", TokensList({"2", "-", "+2"}) ),

    std::make_tuple( "1 + +1", TokensList({"1", "+", "+1"}) ),
    std::make_tuple( "1 + -1", TokensList({"1", "+", "-1"}) ),
    std::make_tuple( "2 - -2", TokensList({"2", "-", "-2"}) ),
    std::make_tuple( "2 - +2", TokensList({"2", "-", "+2"}) ),
};

static std::tuple< std::string, TokensList > lSingleCharacter[] = {
    std::make_tuple( "1", TokensList({"1"}) ),
    std::make_tuple( "a", TokensList({"a"}) ),
    std::make_tuple( "B", TokensList({"B"}) ),
    std::make_tuple( "+", TokensList({"+"}) ),
    std::make_tuple( "-", TokensList({"-"}) ),
    std::make_tuple( "*", TokensList({"*"}) ),
    std::make_tuple( "^", TokensList({"^"}) ),
    std::make_tuple( "/", TokensList({"/"}) ),
    std::make_tuple( "(", TokensList({"("}) ),
    std::make_tuple( ")", TokensList({")"}) ),
    std::make_tuple( "&", TokensList({"&"}) ),
    std::make_tuple( "|", TokensList({"|"}) ),
};

static std::tuple< std::string, TokensList > lVaria[] = {
    std::make_tuple( "1+", TokensList({"1", "+"}) ),
    std::make_tuple( "2-", TokensList({"2", "-"}) ),
    std::make_tuple( "3*", TokensList({"3", "*"}) ),
    std::make_tuple( "4^", TokensList({"4", "^"}) ),
    std::make_tuple( "5/", TokensList({"5", "/"}) ),
    std::make_tuple( "6(", TokensList({"6", "("}) ),
    std::make_tuple( "7)", TokensList({"7", ")"}) ),
    std::make_tuple( "8&", TokensList({"8", "&"}) ),
    std::make_tuple( "9|", TokensList({"9", "|"}) ),

    std::make_tuple( "+1", TokensList({"+1"}) ),
    std::make_tuple( "-2", TokensList({"-2"}) ),
    std::make_tuple( "*3", TokensList({"*", "3"}) ),
    std::make_tuple( "^4", TokensList({"^", "4"}) ),
    std::make_tuple( "/5", TokensList({"/", "5"}) ),
    std::make_tuple( "(6", TokensList({"(", "6"}) ),
    std::make_tuple( ")7", TokensList({")", "7"}) ),
    std::make_tuple( "&8", TokensList({"&", "8"}) ),
    std::make_tuple( "|9", TokensList({"|", "9"}) ),

    std::make_tuple( "1+1", TokensList({"1", "+", "1"}) ),
    std::make_tuple( "2-2", TokensList({"2", "-", "2"}) ),
    std::make_tuple( "3*3", TokensList({"3", "*", "3"}) ),
    std::make_tuple( "4^4", TokensList({"4", "^", "4"}) ),
    std::make_tuple( "5/5", TokensList({"5", "/", "5"}) ),
    std::make_tuple( "6(6", TokensList({"6", "(", "6"}) ),
    std::make_tuple( "7)7", TokensList({"7", ")", "7"}) ),
    std::make_tuple( "8&8", TokensList({"8", "&", "8"}) ),
    std::make_tuple( "9|9", TokensList({"9", "|", "9"}) ),

    std::make_tuple( "1.09991 + 1.1 + 2 4.19991", TokensList({"1.09991", "+", "1.1", "+", "2", "4.19991"}) ),
};


INSTANTIATE_TEST_CASE_P(Plus_or_minus_and_sign, TestTokenizer, ::testing::ValuesIn( lPlusOrMinusAndSign ) );
INSTANTIATE_TEST_CASE_P(Single_character, TestTokenizer, ::testing::ValuesIn( lSingleCharacter ) );
INSTANTIATE_TEST_CASE_P(Varia, TestTokenizer, ::testing::ValuesIn( lVaria ) );
