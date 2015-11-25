#include "TestOperationsParams.hh"

#include <string>
#include <vector>


using namespace std;

//template< typename >
//TestParams< tuple< Add, Numeric, Numeric > >::TestParams()
//{
//    vector<int>    iArg1Values;
//    vector<int>    iArg2Values;
//    vector<int>    iResultValues;
//    size_t         iNumOfTestValues;

//    TestParams()
//    {
//        static int lArgs1[]   = { -1, -1, -1,  0, 0, 0,  1, 1, 1 };
//        static int lArgs2[]   = { -1,  0,  1, -1, 0, 1, -1, 0, 1 };
//        static int lResults[] = { -2, -1,  0, -1, 0, 1,  0, 1, 2 };

//        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

//        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
//        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
//        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
//    }
//}


//template<>
//struct TestParams< tuple< Sub, Numeric, Numeric > >
//{
//    vector<int>    iArg1Values;
//    vector<int>    iArg2Values;
//    vector<int>    iResultValues;
//    size_t         iNumOfTestValues;

//    TestParams()
//    {
//        static int    lArgs1[]   = { -1, -1, -1,  0, 0,  0,  1, 1, 1 };
//        static int    lArgs2[]   = { -1,  0,  1, -1, 0,  1, -1, 0, 1 };
//        static int    lResults[] = {  0, -1, -2, -1, 0, -1,  2, 1, 0 };

//        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

//        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
//        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
//        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
//    }
//};


//template<>
//struct TestParams< tuple< Mul, Numeric, Numeric > >
//{
//    vector<int>    iArg1Values;
//    vector<int>    iArg2Values;
//    vector<int>    iResultValues;
//    size_t         iNumOfTestValues;

//    TestParams()
//    {
//        static int    lArgs1[]    = { -1, -1, -1,  0, 0,  0,  1, 1, 1 };
//        static int    lArgs2[]    = { -1,  0,  1, -1, 0,  1, -1, 0, 1 };
//        static int    lResults[]  = {  1, 0,  -1, -1, 0,  0, -1, 0, 1 };

//        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

//        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
//        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
//        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
//    }
//};


//template<>
//struct TestParams< tuple< Or, Bool, Bool > >
//{
//    vector<bool>   iArg1Values;
//    vector<bool>   iArg2Values;
//    vector<bool>   iResultValues;
//    size_t         iNumOfTestValues;

//    TestParams()
//    {
//        static bool   lArgs1[]    = { false, false, true,  true };
//        static bool   lArgs2[]    = { false, true,  false, true };
//        static bool   lResults[]  = { false, true,  true,  true };

//        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

//        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
//        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
//        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
//    }
//};


//template<>
//struct TestParams< tuple< Add, Text, Text > >
//{
//    vector<std::string>  iArg1Values;
//    vector<std::string>  iArg2Values;
//    vector<std::string>  iResultValues;
//    size_t               iNumOfTestValues;

//    TestParams()
//    {
//        static const char * lArgs1[]    = {"", "",    "aaa", "aaa", "fff"};
//        static const char * lArgs2[]    = {"", "vvv", "",    "vvv", "aaa"};
//        static const char * lResults[]  = {"", "vvv", "aaa", "aaavvv", "fffaaa"};

//        iNumOfTestValues = sizeof(lArgs1) / sizeof(lArgs1[0]);

//        copy( lArgs1,   lArgs1+iNumOfTestValues,   back_inserter( iArg1Values ) );
//        copy( lArgs2,   lArgs2+iNumOfTestValues,   back_inserter( iArg2Values ) );
//        copy( lResults, lResults+iNumOfTestValues, back_inserter( iResultValues ) );
//    }
//};
