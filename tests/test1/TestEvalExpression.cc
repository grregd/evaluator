
#include "TestEvalExpression.hh"
#include <Factory.hh>


TEST( TestEvalExpression, singleShot )
{
    ASSERT_EQ( "4.19991", Factory::evalExpression( "1.09991 + 1.1 + 2" ) );
}

TEST_P(TestEvalExpression, evaluating)
{
    const char * lInput  = std::get< 0 >( GetParam() );
    const char * lExpected = std::get< 1 >( GetParam() );
    ASSERT_EQ( lExpected, Factory::evalExpression( lInput ) );
}

std::tuple< const char *, const char * > lOneValue[] = {
    std::make_tuple( "", "" ),
    std::make_tuple( "-1", "-1" ),
    std::make_tuple( "0", "0" ),
    std::make_tuple( "1", "1" ),
    std::make_tuple( "2", "2" ),

    std::make_tuple( "-01", "-1" ),
    std::make_tuple( "00", "0" ),
    std::make_tuple( "01", "1" ),
    std::make_tuple( "02", "2" ),

    std::make_tuple( "-010", "-10" ),
    std::make_tuple( "000", "0" ),
    std::make_tuple( "010", "10" ),
    std::make_tuple( "020", "20" ),

//    std::make_tuple( "a", "0" ),
//    std::make_tuple( "b", "0" ),
};

std::tuple< const char *, const char * > lOneAddText[] = {
};

std::tuple< const char *, const char * > lOneAddPositive[] = {
    std::make_tuple( "0+0", "0" ),
    std::make_tuple( "0 +0", "0" ),
    std::make_tuple( "0+ 0", "0" ),
    std::make_tuple( "0 + 0", "0" ),

    std::make_tuple( "0+1", "1" ),
    std::make_tuple( "0 +1", "1" ),
    std::make_tuple( "0+ 1", "1" ),
    std::make_tuple( "0 + 1", "1" ),

    std::make_tuple( "1+0", "1" ),
    std::make_tuple( "1 +0", "1" ),
    std::make_tuple( "1+ 0", "1" ),
    std::make_tuple( "1 + 0", "1" ),
};


std::tuple< const char *, const char * > lOneAddNegative[] = {
    std::make_tuple( "-0+0", "0" ),
    std::make_tuple( "-0 +0", "0" ),
    std::make_tuple( "-0+ 0", "0" ),
    std::make_tuple( "-0 + 0", "0" ),
    std::make_tuple( "0+-0", "0" ),
    std::make_tuple( "0 +-0", "0" ),
    std::make_tuple( "0+ -0", "0" ),
    std::make_tuple( "0 + -0", "0" ),
    std::make_tuple( "-0+-0", "-0" ),
    std::make_tuple( "-0 +-0", "-0" ),
    std::make_tuple( "-0+ -0", "-0" ),
    std::make_tuple( "-0 + -0", "-0" ),

    std::make_tuple( "-0+1", "1" ),
    std::make_tuple( "-0 +1", "1" ),
    std::make_tuple( "-0+ 1", "1" ),
    std::make_tuple( "-0 + 1", "1" ),
    std::make_tuple( "0+-1", "-1" ),
    std::make_tuple( "0 +-1", "-1" ),
    std::make_tuple( "0+ -1", "-1" ),
    std::make_tuple( "0 + -1", "-1" ),
    std::make_tuple( "-0+-1", "-1" ),
    std::make_tuple( "-0 +-1", "-1" ),
    std::make_tuple( "-0+ -1", "-1" ),
    std::make_tuple( "-0 + -1", "-1" ),

    std::make_tuple( "-1+0", "-1" ),
    std::make_tuple( "-1 +0", "-1" ),
    std::make_tuple( "-1+ 0", "-1" ),
    std::make_tuple( "-1 + 0", "-1" ),
    std::make_tuple( "1+-0", "1" ),
    std::make_tuple( "1 +-0", "1" ),
    std::make_tuple( "1+ -0", "1" ),
    std::make_tuple( "1 + -0", "1" ),
    std::make_tuple( "-1+-0", "-1" ),
    std::make_tuple( "-1 +-0", "-1" ),
    std::make_tuple( "-1+ -0", "-1" ),
    std::make_tuple( "-1 + -0", "-1" ),
};

std::tuple< const char *, const char * > lOneSubPositive[] = {
    std::make_tuple( "0-0", "0" ),
    std::make_tuple( "0 -0", "0" ),
    std::make_tuple( "0- 0", "0" ),
    std::make_tuple( "0 - 0", "0" ),

    std::make_tuple( "0-1", "-1" ),
    std::make_tuple( "0 -1", "-1" ),
    std::make_tuple( "0- 1", "-1" ),
    std::make_tuple( "0 - 1", "-1" ),

    std::make_tuple( "1-0", "1" ),
    std::make_tuple( "1 -0", "1" ),
    std::make_tuple( "1- 0", "1" ),
    std::make_tuple( "1 - 0", "1" ),
};

std::tuple< const char *, const char * > lOneSubNegative[] = {
    std::make_tuple( "-0-0", "-0" ),
    std::make_tuple( "-0 -0", "-0" ),
    std::make_tuple( "-0- 0", "-0" ),
    std::make_tuple( "-0 - 0", "-0" ),
    std::make_tuple( "0--0", "0" ), // is it correct?
    std::make_tuple( "0 --0", "0" ),
    std::make_tuple( "0- -0", "0" ),
    std::make_tuple( "0 - -0", "0" ),
    std::make_tuple( "-0--0", "0" ), // is it correct?
    std::make_tuple( "-0 --0", "0" ), // is it correct?
    std::make_tuple( "-0- -0", "0" ),
    std::make_tuple( "-0 - -0", "0" ),

    std::make_tuple( "0-1", "-1" ),
    std::make_tuple( "0 -1", "-1" ),
    std::make_tuple( "0- 1", "-1" ),
    std::make_tuple( "0 - 1", "-1" ),
    std::make_tuple( "0-1", "-1" ),
    std::make_tuple( "0 -1", "-1" ),
    std::make_tuple( "0- 1", "-1" ),
    std::make_tuple( "0 - 1", "-1" ),
    std::make_tuple( "0-1", "-1" ),
    std::make_tuple( "0 -1", "-1" ),
    std::make_tuple( "0- 1", "-1" ),
    std::make_tuple( "0 - 1", "-1" ),

    std::make_tuple( "1-0", "1" ),
    std::make_tuple( "1 -0", "1" ),
    std::make_tuple( "1- 0", "1" ),
    std::make_tuple( "1 - 0", "1" ),
    std::make_tuple( "1-0", "1" ),
    std::make_tuple( "1 -0", "1" ),
    std::make_tuple( "1- 0", "1" ),
    std::make_tuple( "1 - 0", "1" ),
    std::make_tuple( "1-0", "1" ),
    std::make_tuple( "1 -0", "1" ),
    std::make_tuple( "1- 0", "1" ),
    std::make_tuple( "1 - 0", "1" ),
};

std::tuple< const char *, const char * > lBoolean[] = {
    std::make_tuple( "false|false", "false" ),
    std::make_tuple( "false|true",  "true" ),
    std::make_tuple( "true|false",  "true" ),
    std::make_tuple( "true|true",  "true" ),

    std::make_tuple( "false| false", "false" ),
    std::make_tuple( "false| true",  "true" ),
    std::make_tuple( "true| false",  "true" ),
    std::make_tuple( "true| true",  "true" ),

    std::make_tuple( "false |false", "false" ),
    std::make_tuple( "false |true",  "true" ),
    std::make_tuple( "true |false",  "true" ),
    std::make_tuple( "true |true",  "true" ),

    std::make_tuple( "false | false", "false" ),
    std::make_tuple( "false | true",  "true" ),
    std::make_tuple( "true | false",  "true" ),
    std::make_tuple( "true | true",  "true" ),

    std::make_tuple( "false&false", "false" ),
    std::make_tuple( "false&true",  "false" ),
    std::make_tuple( "true&false",  "false" ),
    std::make_tuple( "true&true",  "true" ),

    std::make_tuple( "false& false", "false" ),
    std::make_tuple( "false& true",  "false" ),
    std::make_tuple( "true& false",  "false" ),
    std::make_tuple( "true& true",  "true" ),

    std::make_tuple( "false &false", "false" ),
    std::make_tuple( "false &true",  "false" ),
    std::make_tuple( "true &false",  "false" ),
    std::make_tuple( "true &true",  "true" ),

    std::make_tuple( "false & false", "false" ),
    std::make_tuple( "false & true",  "false" ),
    std::make_tuple( "true & false",  "false" ),
    std::make_tuple( "true & true",  "true" ),
};

std::tuple< const char *, const char * > lVaria[] = {
    std::make_tuple( "1.09991 + 1.1 + 2", "4.19991" ),
};

INSTANTIATE_TEST_CASE_P(OneValue,         TestEvalExpression, ::testing::ValuesIn( lOneValue ) );
INSTANTIATE_TEST_CASE_P(OneAddPositive,   TestEvalExpression, ::testing::ValuesIn( lOneAddPositive ) );
INSTANTIATE_TEST_CASE_P(OneAddNegative,   TestEvalExpression, ::testing::ValuesIn( lOneAddNegative ) );
INSTANTIATE_TEST_CASE_P(OneSubPositive,   TestEvalExpression, ::testing::ValuesIn( lOneSubPositive ) );
INSTANTIATE_TEST_CASE_P(OneSubNegative,   TestEvalExpression, ::testing::ValuesIn( lOneSubNegative ) );
INSTANTIATE_TEST_CASE_P(Boolean,          TestEvalExpression, ::testing::ValuesIn( lBoolean ) );
INSTANTIATE_TEST_CASE_P(Varia,            TestEvalExpression, ::testing::ValuesIn( lVaria ) );

