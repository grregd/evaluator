#pragma once

#include <tr1/tuple>

#include <string>
#include <vector>


#include <operations.hh>
#include <operands.hh>
#include <evaluators.hh>

using namespace std;
using namespace std::tr1;

using namespace Operations;
using namespace Operands;
using namespace Evaluators;



template< typename T >
struct TestParams
{
};

template<>
struct TestParams< tuple< Not, Bool > >
{
    vector<bool>    iArg1Values;
    vector<bool>    iResultValues;
    size_t          iNumOfTestValues;

    TestParams()
    {
        static NumericType lArgs1[]   = { false, true };
        static NumericType lResults[] = { true, false };

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};


template<>
struct TestParams< tuple< Add, Numeric, Numeric, Numeric > >
{
    vector<NumericType>    iArg1Values;
    vector<NumericType>    iArg2Values;
    vector<NumericType>    iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static NumericType lArgs1[]   = { -1, -1, -1,  0, 0, 0,  1, 1, 1 };
        static NumericType lArgs2[]   = { -1,  0,  1, -1, 0, 1, -1, 0, 1 };
        static NumericType lResults[] = { -2, -1,  0, -1, 0, 1,  0, 1, 2 };

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

template<>
struct TestParams< tuple< Sub, Numeric, Numeric, Numeric > >
{
    vector<NumericType>    iArg1Values;
    vector<NumericType>    iArg2Values;
    vector<NumericType>    iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static NumericType    lArgs1[]   = { -1, -1, -1,  0, 0,  0,  1, 1, 1 };
        static NumericType    lArgs2[]   = { -1,  0,  1, -1, 0,  1, -1, 0, 1 };
        static NumericType    lResults[] = {  0, -1, -2,  1, 0, -1,  2, 1, 0 };

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

template<>
struct TestParams< tuple< Mul, Numeric, Numeric, Numeric > >
{
    vector<NumericType>    iArg1Values;
    vector<NumericType>    iArg2Values;
    vector<NumericType>    iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static NumericType    lArgs1[]    = { -1, -1, -1,  0, 0,  0,  1, 1, 1 };
        static NumericType    lArgs2[]    = { -1,  0,  1, -1, 0,  1, -1, 0, 1 };
        static NumericType    lResults[]  = {  1, 0,  -1,  0, 0,  0, -1, 0, 1 };

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

template<>
struct TestParams< tuple< Div, Numeric, Numeric, Numeric > >
{
    vector<NumericType>    iArg1Values;
    vector<NumericType>    iArg2Values;
    vector<NumericType>    iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static NumericType    lArgs1[]    = { 1,   0, };
        static NumericType    lArgs2[]    = { 2,   1, };
        static NumericType    lResults[]  = { 0.5, 0, };

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

template<>
struct TestParams< tuple< Gt, Numeric, Numeric, Bool > >
{
    vector<NumericType>    iArg1Values;
    vector<NumericType>    iArg2Values;
    vector<NumericType>    iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static NumericType    lArgs1[]   = { -1,    0,    1,   -1,     0,     1,   -1,     0,     1 };
        static NumericType    lArgs2[]   = { -1,   -1,   -1,    0,     0,     0,    1,     1,     1 };
        static bool           lResults[] = { false, true, true, false, false, true, false, false, false};

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

template<>
struct TestParams< tuple< Ge, Numeric, Numeric, Bool > >
{
    vector<NumericType>    iArg1Values;
    vector<NumericType>    iArg2Values;
    vector<NumericType>    iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static NumericType    lArgs1[]   = { -1,    0,    1,   -1,     0,     1,   -1,     0,     1 };
        static NumericType    lArgs2[]   = { -1,   -1,   -1,    0,     0,     0,    1,     1,     1 };
        static bool           lResults[] = { true,  true, true, false, true,  true, false, false, true};

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

template<>
struct TestParams< tuple< Lt, Numeric, Numeric, Bool > >
{
    vector<NumericType>    iArg1Values;
    vector<NumericType>    iArg2Values;
    vector<NumericType>    iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static NumericType    lArgs1[]   = { -1,    0,    1,   -1,     0,     1,   -1,     0,     1 };
        static NumericType    lArgs2[]   = { -1,   -1,   -1,    0,     0,     0,    1,     1,     1 };
        static bool           lResults[] = { false, false, false, true, false,  false, true, true, false};

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

template<>
struct TestParams< tuple< Le, Numeric, Numeric, Bool > >
{
    vector<NumericType>    iArg1Values;
    vector<NumericType>    iArg2Values;
    vector<NumericType>    iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static NumericType    lArgs1[]   = { -1,    0,    1,   -1,     0,     1,   -1,     0,     1 };
        static NumericType    lArgs2[]   = { -1,   -1,   -1,    0,     0,     0,    1,     1,     1 };
        static bool           lResults[] = { true, false, false, true, true, false, true, true, true};

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};


template<>
struct TestParams< tuple< Or, Bool, Bool, Bool > >
{
    vector<bool>   iArg1Values;
    vector<bool>   iArg2Values;
    vector<bool>   iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static bool   lArgs1[]    = { false, false, true,  true };
        static bool   lArgs2[]    = { false, true,  false, true };
        static bool   lResults[]  = { false, true,  true,  true };

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

template<>
struct TestParams< tuple< And, Bool, Bool, Bool > >
{
    vector<bool>   iArg1Values;
    vector<bool>   iArg2Values;
    vector<bool>   iResultValues;
    size_t         iNumOfTestValues;

    TestParams()
    {
        static bool   lArgs1[]    = { false, false, true,  true };
        static bool   lArgs2[]    = { false, true,  false, true };
        static bool   lResults[]  = { false, false, false, true };

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};




template<>
struct TestParams< tuple< Add, Text, Text, Text > >
{
    vector<std::string>  iArg1Values;
    vector<std::string>  iArg2Values;
    vector<std::string>  iResultValues;
    size_t               iNumOfTestValues;

    TestParams()
    {
        static const char * lArgs1[]    = {"", "",    "aaa", "aaa", "fff"};
        static const char * lArgs2[]    = {"", "vvv", "",    "vvv", "aaa"};
        static const char * lResults[]  = {"", "vvv", "aaa", "aaavvv", "fffaaa"};

        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
    }
};

