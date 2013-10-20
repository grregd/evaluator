
#include "TestEvalExpression.hh"
#include <Factory.hh>


TEST_P(TestEvalExpression, evaluating)
{
    const char * lInput  = std::tr1::get< 0 >( GetParam() );
    const char * lOutput = std::tr1::get< 1 >( GetParam() );
    //    {
    //        std::string lExpressions[] = { "1.09991 + 1.1 + 2" };
    //        std::for_each( lExpressions, lExpressions+1,  )
            std::cout << lInput << " = " << Factory::evalExpression( lInput ) << std::endl;
            ASSERT_EQ( lOutput, Factory::evalExpression( lInput ) );
    //    }

}

std::tr1::tuple< const char *, const char * > lOneValue[] = {
    std::tr1::make_tuple( "", "" ),
    std::tr1::make_tuple( "-1", "-1" ),
    std::tr1::make_tuple( "0", "0" ),
    std::tr1::make_tuple( "1", "1" ),
    std::tr1::make_tuple( "2", "2" ),

    std::tr1::make_tuple( "-01", "-1" ),
    std::tr1::make_tuple( "00", "0" ),
    std::tr1::make_tuple( "01", "1" ),
    std::tr1::make_tuple( "02", "2" ),

    std::tr1::make_tuple( "-010", "-10" ),
    std::tr1::make_tuple( "000", "0" ),
    std::tr1::make_tuple( "010", "10" ),
    std::tr1::make_tuple( "020", "20" ),

    std::tr1::make_tuple( "a", "0" ),
    std::tr1::make_tuple( "b", "0" ),
};

std::tr1::tuple< const char *, const char * > lOneAddText[] = {
};

std::tr1::tuple< const char *, const char * > lOneAddPositive[] = {
    std::tr1::make_tuple( "0+0", "0" ),
    std::tr1::make_tuple( "0 +0", "0" ),
    std::tr1::make_tuple( "0+ 0", "0" ),
    std::tr1::make_tuple( "0 + 0", "0" ),

    std::tr1::make_tuple( "0+1", "1" ),
    std::tr1::make_tuple( "0 +1", "1" ),
    std::tr1::make_tuple( "0+ 1", "1" ),
    std::tr1::make_tuple( "0 + 1", "1" ),

    std::tr1::make_tuple( "1+0", "1" ),
    std::tr1::make_tuple( "1 +0", "1" ),
    std::tr1::make_tuple( "1+ 0", "1" ),
    std::tr1::make_tuple( "1 + 0", "1" ),
};


std::tr1::tuple< const char *, const char * > lOneAddNegative[] = {
    std::tr1::make_tuple( "-0+0", "0" ),
    std::tr1::make_tuple( "-0 +0", "0" ),
    std::tr1::make_tuple( "-0+ 0", "0" ),
    std::tr1::make_tuple( "-0 + 0", "0" ),
    std::tr1::make_tuple( "0+-0", "0" ),
    std::tr1::make_tuple( "0 +-0", "0" ),
    std::tr1::make_tuple( "0+ -0", "0" ),
    std::tr1::make_tuple( "0 + -0", "0" ),
    std::tr1::make_tuple( "-0+-0", "0" ),
    std::tr1::make_tuple( "-0 +-0", "0" ),
    std::tr1::make_tuple( "-0+ -0", "0" ),
    std::tr1::make_tuple( "-0 + -0", "0" ),

    std::tr1::make_tuple( "-0+1", "1" ),
    std::tr1::make_tuple( "-0 +1", "1" ),
    std::tr1::make_tuple( "-0+ 1", "1" ),
    std::tr1::make_tuple( "-0 + 1", "1" ),
    std::tr1::make_tuple( "0+-1", "-1" ),
    std::tr1::make_tuple( "0 +-1", "-1" ),
    std::tr1::make_tuple( "0+ -1", "-1" ),
    std::tr1::make_tuple( "0 + -1", "-1" ),
    std::tr1::make_tuple( "-0+-1", "-1" ),
    std::tr1::make_tuple( "-0 +-1", "-1" ),
    std::tr1::make_tuple( "-0+ -1", "-1" ),
    std::tr1::make_tuple( "-0 + -1", "-1" ),

    std::tr1::make_tuple( "-1+0", "-1" ),
    std::tr1::make_tuple( "-1 +0", "-1" ),
    std::tr1::make_tuple( "-1+ 0", "-1" ),
    std::tr1::make_tuple( "-1 + 0", "-1" ),
    std::tr1::make_tuple( "1+-0", "1" ),
    std::tr1::make_tuple( "1 +-0", "1" ),
    std::tr1::make_tuple( "1+ -0", "1" ),
    std::tr1::make_tuple( "1 + -0", "1" ),
    std::tr1::make_tuple( "-1+-0", "-1" ),
    std::tr1::make_tuple( "-1 +-0", "-1" ),
    std::tr1::make_tuple( "-1+ -0", "-1" ),
    std::tr1::make_tuple( "-1 + -0", "-1" ),
};

std::tr1::tuple< const char *, const char * > lOneSubPositive[] = {
    std::tr1::make_tuple( "0-0", "0" ),
    std::tr1::make_tuple( "0 -0", "0" ),
    std::tr1::make_tuple( "0- 0", "0" ),
    std::tr1::make_tuple( "0 - 0", "0" ),

    std::tr1::make_tuple( "0-1", "1" ),
    std::tr1::make_tuple( "0 -1", "1" ),
    std::tr1::make_tuple( "0- 1", "1" ),
    std::tr1::make_tuple( "0 - 1", "1" ),

    std::tr1::make_tuple( "1-0", "1" ),
    std::tr1::make_tuple( "1 -0", "1" ),
    std::tr1::make_tuple( "1- 0", "1" ),
    std::tr1::make_tuple( "1 - 0", "1" ),
};

std::tr1::tuple< const char *, const char * > lOneSubNegative[] = {
    std::tr1::make_tuple( "-0-0", "0" ),
    std::tr1::make_tuple( "-0 -0", "0" ),
    std::tr1::make_tuple( "-0- 0", "0" ),
    std::tr1::make_tuple( "-0 - 0", "0" ),
    std::tr1::make_tuple( "0--0", "0" ), // is it correct?
    std::tr1::make_tuple( "0 --0", "0" ),
    std::tr1::make_tuple( "0- -0", "0" ),
    std::tr1::make_tuple( "0 - -0", "0" ),
    std::tr1::make_tuple( "-0--0", "0" ), // is it correct?
    std::tr1::make_tuple( "-0 --0", "0" ), // is it correct?
    std::tr1::make_tuple( "-0- -0", "0" ),
    std::tr1::make_tuple( "-0 - -0", "0" ),

    std::tr1::make_tuple( "0-1", "1" ),
    std::tr1::make_tuple( "0 -1", "1" ),
    std::tr1::make_tuple( "0- 1", "1" ),
    std::tr1::make_tuple( "0 - 1", "1" ),
    std::tr1::make_tuple( "0-1", "1" ),
    std::tr1::make_tuple( "0 -1", "1" ),
    std::tr1::make_tuple( "0- 1", "1" ),
    std::tr1::make_tuple( "0 - 1", "1" ),
    std::tr1::make_tuple( "0-1", "1" ),
    std::tr1::make_tuple( "0 -1", "1" ),
    std::tr1::make_tuple( "0- 1", "1" ),
    std::tr1::make_tuple( "0 - 1", "1" ),

    std::tr1::make_tuple( "1-0", "1" ),
    std::tr1::make_tuple( "1 -0", "1" ),
    std::tr1::make_tuple( "1- 0", "1" ),
    std::tr1::make_tuple( "1 - 0", "1" ),
    std::tr1::make_tuple( "1-0", "1" ),
    std::tr1::make_tuple( "1 -0", "1" ),
    std::tr1::make_tuple( "1- 0", "1" ),
    std::tr1::make_tuple( "1 - 0", "1" ),
    std::tr1::make_tuple( "1-0", "1" ),
    std::tr1::make_tuple( "1 -0", "1" ),
    std::tr1::make_tuple( "1- 0", "1" ),
    std::tr1::make_tuple( "1 - 0", "1" ),
};

std::tr1::tuple< const char *, const char * > lVaria[] = {
    std::tr1::make_tuple( "1.09991 + 1.1 + 2", "4.19991" ),
};

INSTANTIATE_TEST_CASE_P(OneValue,         TestEvalExpression, ::testing::ValuesIn( lOneValue ) );
INSTANTIATE_TEST_CASE_P(OneAddPositive,   TestEvalExpression, ::testing::ValuesIn( lOneAddPositive ) );
INSTANTIATE_TEST_CASE_P(OneAddNegative,   TestEvalExpression, ::testing::ValuesIn( lOneAddNegative ) );
INSTANTIATE_TEST_CASE_P(OneSubPositive,   TestEvalExpression, ::testing::ValuesIn( lOneSubPositive ) );
INSTANTIATE_TEST_CASE_P(OneSubNegative,   TestEvalExpression, ::testing::ValuesIn( lOneSubNegative ) );
INSTANTIATE_TEST_CASE_P(Varia,            TestEvalExpression, ::testing::ValuesIn( lVaria ) );

