
#include <tuple>
#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <operations.hh>
#include <operands.hh>
#include <evaluators.hh>

#include "testparams.hh"

using namespace std;

using namespace Operations;
using namespace Operands;
using namespace Evaluators;


template< typename T >
class OneArgOperationTest: public testing::Test
{
public:
    typedef typename tuple_element< 0, T >::type OperationType;
    typedef typename tuple_element< 1, T >::type Arg1Type;
    typedef typename tuple_element< 1, T >::type ResultType;

    typedef shared_ptr< typename tuple_element< 0, T >::type > OperationTypePtr;
    typedef shared_ptr< typename tuple_element< 1, T >::type > Arg1TypePtr;
    typedef shared_ptr< typename tuple_element< 1, T >::type > ResultTypePtr;

public:
    OneArgOperationTest() {}

protected:
    TestParams< T > iTestParams;
};


template< typename T >
class TwoArgsOperationTest: public testing::Test
{
public:
    typedef typename tuple_element< 0, T >::type OperationType;
    typedef typename tuple_element< 1, T >::type Arg1Type;
    typedef typename tuple_element< 2, T >::type Arg2Type;
    typedef typename tuple_element< 3, T >::type ResultType;

    typedef shared_ptr< typename tuple_element< 0, T >::type > OperationTypePtr;
    typedef shared_ptr< typename tuple_element< 1, T >::type > Arg1TypePtr;
    typedef shared_ptr< typename tuple_element< 2, T >::type > Arg2TypePtr;
    typedef shared_ptr< typename tuple_element< 3, T >::type > ResultTypePtr;

public:
    TwoArgsOperationTest() {}

protected:
    TestParams< T > iTestParams;
};

TYPED_TEST_CASE_P( OneArgOperationTest );
TYPED_TEST_CASE_P( TwoArgsOperationTest );


TYPED_TEST_P( OneArgOperationTest, nullPtrOperation )
{
    typedef typename OneArgOperationTest< TypeParam >::OperationType OperationType;

    ExpressionTokensStack  lStack;
    Evaluator              lEvaluator;

    ASSERT_NO_THROW( lStack.push( typename OperationType::Ptr( ) ) );
    ASSERT_THROW( Evaluators::evaluate( lStack, lEvaluator ), std::runtime_error );
}

TYPED_TEST_P( OneArgOperationTest, lackOfArgs )
{
    typedef typename OneArgOperationTest< TypeParam >::OperationType OperationType;

    typedef typename OneArgOperationTest< TypeParam >::Arg1Type      Arg1Type;
    typedef typename OneArgOperationTest< TypeParam >::ResultType    ResultType;

    {
        ExpressionTokensStack  lStack;
        Evaluator              lEvaluator;

        ASSERT_NO_THROW( lStack.push( typename OperationType::Ptr( new OperationType() ) ) );
        ASSERT_THROW( Evaluators::evaluate( lStack, lEvaluator ), std::runtime_error );
    }
}

TYPED_TEST_P( OneArgOperationTest, exec )
{
    typedef typename OneArgOperationTest< TypeParam >::OperationType OperationType;
    typedef typename OneArgOperationTest< TypeParam >::Arg1Type      Arg1Type;
    typedef typename OneArgOperationTest< TypeParam >::ResultType    ResultType;

    for ( size_t i = 0; i < this->iTestParams.iNumOfTestValues; ++i )
    {
        ExpressionTokensStack     lStack;
        Evaluator                 lEvaluator;
        typename ResultType::Ptr  lResultObject;

        ASSERT_NO_THROW( lStack.push( typename OperationType::Ptr( new OperationType() ) ) );
        ASSERT_NO_THROW( lStack.push( typename Arg1Type::Ptr( new Arg1Type( this->iTestParams.iArg1Values[i] ) ) ) );

        ASSERT_NO_THROW( Evaluators::evaluate( lStack, lEvaluator ) );

        ASSERT_EQ( 1, lEvaluator.getOperandsStack().size() );
        ASSERT_TRUE( (bool)(lResultObject = dynamic_pointer_cast<ResultType>(lEvaluator.getOperandsStack().top())) );
        ASSERT_TRUE( (bool)lResultObject );
        ASSERT_EQ( this->iTestParams.iResultValues[i], lResultObject->getValue() );
    }
}



TYPED_TEST_P( TwoArgsOperationTest, nullPtrOperation )
{
    typedef typename TwoArgsOperationTest< TypeParam >::OperationType OperationType;

    ExpressionTokensStack  lStack;
    Evaluator              lEvaluator;

    ASSERT_NO_THROW( lStack.push( typename OperationType::Ptr( ) ) );
    ASSERT_THROW( Evaluators::evaluate( lStack, lEvaluator ), std::runtime_error );
}


TYPED_TEST_P( TwoArgsOperationTest, lackOfArgs )
{
    typedef typename TwoArgsOperationTest< TypeParam >::OperationType OperationType;
    typedef typename TwoArgsOperationTest< TypeParam >::Arg1Type      Arg1Type;
    typedef typename TwoArgsOperationTest< TypeParam >::Arg2Type      Arg2Type;
    typedef typename TwoArgsOperationTest< TypeParam >::ResultType    ResultType;

    {
        ExpressionTokensStack  lStack;
        Evaluator              lEvaluator;

        ASSERT_NO_THROW( lStack.push( typename OperationType::Ptr( new OperationType() ) ) );
        ASSERT_THROW( Evaluators::evaluate( lStack, lEvaluator ), std::runtime_error );
    }

    {
        ExpressionTokensStack  lStack;
        Evaluator              lEvaluator;

        ASSERT_NO_THROW( lStack.push( typename OperationType::Ptr( new OperationType() ) ) );
        ASSERT_NO_THROW( lStack.push( typename Arg1Type::Ptr( new Arg1Type( this->iTestParams.iArg1Values[0] ) ) ) );
        ASSERT_THROW( Evaluators::evaluate( lStack, lEvaluator ), std::runtime_error );
    }

    {
        ExpressionTokensStack  lStack;
        Evaluator              lEvaluator;

        ASSERT_NO_THROW( lStack.push( typename OperationType::Ptr( new OperationType() ) ) );
        ASSERT_NO_THROW( lStack.push( typename Arg2Type::Ptr( new Arg2Type( this->iTestParams.iArg2Values[0] ) ) ) );
        ASSERT_THROW( Evaluators::evaluate( lStack, lEvaluator ), std::runtime_error );
    }
}

TYPED_TEST_P( TwoArgsOperationTest, exec )
{
    typedef typename TwoArgsOperationTest< TypeParam >::OperationType OperationType;
    typedef typename TwoArgsOperationTest< TypeParam >::Arg1Type      Arg1Type;
    typedef typename TwoArgsOperationTest< TypeParam >::Arg2Type      Arg2Type;
    typedef typename TwoArgsOperationTest< TypeParam >::ResultType    ResultType;

    for ( size_t i = 0; i < this->iTestParams.iNumOfTestValues; ++i )
    {
        ExpressionTokensStack     lStack;
        Evaluator                 lEvaluator;
        typename ResultType::Ptr  lResultObject;

        ASSERT_NO_THROW( lStack.push( typename OperationType::Ptr( new OperationType() ) ) );
        ASSERT_NO_THROW( lStack.push( typename Arg1Type::Ptr( new Arg1Type( this->iTestParams.iArg1Values[i] ) ) ) );
        ASSERT_NO_THROW( lStack.push( typename Arg2Type::Ptr( new Arg2Type( this->iTestParams.iArg2Values[i] ) ) ) );

        ASSERT_NO_THROW( Evaluators::evaluate( lStack, lEvaluator ) );

        ASSERT_EQ( 1, lEvaluator.getOperandsStack().size() )
                << "Arg1: " << this->iTestParams.iArg1Values[i] << ", Arg2: " << this->iTestParams.iArg2Values[i];
        ASSERT_TRUE( (bool)(lResultObject = dynamic_pointer_cast<ResultType>(lEvaluator.getOperandsStack().top())) );
        ASSERT_TRUE( (bool)lResultObject );
        ASSERT_EQ( this->iTestParams.iResultValues[i], lResultObject->getValue() )
                << "Arg1: " << this->iTestParams.iArg1Values[i] << ", Arg2: " << this->iTestParams.iArg2Values[i];
    }
}

REGISTER_TYPED_TEST_CASE_P( OneArgOperationTest,
                            nullPtrOperation,
                            lackOfArgs,
                            exec );

typedef ::testing::Types
    <
      tuple< Not, Bool >
    > OneArgTypes;


REGISTER_TYPED_TEST_CASE_P( TwoArgsOperationTest,
                            nullPtrOperation,
                            lackOfArgs,
                            exec );

typedef ::testing::Types
    <
      tuple< Add, Numeric, Numeric, Numeric >
    , tuple< Sub, Numeric, Numeric, Numeric >
    , tuple< Mul, Numeric, Numeric, Numeric >
    , tuple< Div, Numeric, Numeric, Numeric >
    , tuple< Gt,  Numeric, Numeric, Bool >
    , tuple< Ge,  Numeric, Numeric, Bool >
    , tuple< Lt,  Numeric, Numeric, Bool >
    , tuple< Le,  Numeric, Numeric, Bool >
    , tuple< Or,  Bool,    Bool,    Bool >
    , tuple< And, Bool,    Bool,    Bool >
    , tuple< Add, Text,    Text,    Text >
    > TwoArgsTypes;

INSTANTIATE_TYPED_TEST_CASE_P(My, OneArgOperationTest, OneArgTypes);
INSTANTIATE_TYPED_TEST_CASE_P(My, TwoArgsOperationTest, TwoArgsTypes);

