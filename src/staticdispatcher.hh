#ifndef __STATICDISPATCHER_HH__
#define __STATICDISPATCHER_HH__

#include <tuple>
#include <typeinfo>
#include <map>
#include <stdexcept>


//typedef std::tuple<> NullType;


//template <
//    class Executor,
//    class BaseLhs,
//    class TypesLhs, // tuple
//    int   IndexLhs, // tuple's index
//    class BaseRhs = BaseLhs,
//    class TypesRhs = TypesLhs,
//    int   IndexRhs = IndexLhs,
//    typename ResultType = int
//>
//class StaticDispatcher
//{
//    //typedef typename TypesLhs::Head Head;
//    typedef typename std::tuple_element<IndexLhs-1, TypesLhs>::type Head;
//    //typedef typename TypesLhs::Tail Tail;


//public:

//    // DispatchRhs
//    template <class SomeLhs>
//    static ResultType DispatchRhs(SomeLhs& lhs, BaseRhs& rhs,
//                                  Executor exec)
//    {
////        typedef typename TypesRhs::Head Head;
//        typedef typename std::tuple_element<IndexRhs-1, TypesRhs>::type Head;
////        typedef typename TypesRhs::Tail Tail;
//        if (Head* p2 = dynamic_cast<Head*>(&rhs))
//        {
//            return exec.Fire(lhs, *p2);
//        }
//        else
//        {
//            return StaticDispatcher<Executor,
//                    SomeLhs, NullType, IndexLhs,
//                    BaseRhs, TypesRhs, /*Tail*/IndexRhs-1>::DispatchRhs(lhs, rhs, exec);
//        }
//    }


//    // Go
//    static ResultType Go(BaseLhs& lhs, BaseRhs& rhs,
//                         Executor exec)
//    {
//        if (Head* p1 = dynamic_cast<Head*>(&lhs))
//        {
//            return StaticDispatcher<Executor,
//                    BaseLhs, NullType, IndexLhs,
//                    BaseRhs, TypesRhs, IndexRhs >::DispatchRhs(*p1, rhs, exec);
//        }
//        else
//        {
//            return StaticDispatcher<Executor,
//                    BaseLhs, TypesLhs, /*Tail*/IndexLhs-1,
//                    BaseRhs, TypesRhs, IndexRhs>::Go(lhs, rhs, exec);
//        }
//    }

//};

//template <
//    class Executor,
//    class BaseLhs,
//    class BaseRhs,
//    class TypesRhs,
//    int   IndexRhs,
//    typename ResultType
//>
//class StaticDispatcher<Executor, BaseLhs, NullType, 0,
//        BaseRhs, TypesRhs, IndexRhs, ResultType>
//{
//public:
//    static ResultType DispatchRhs(BaseLhs& lhs, BaseRhs& rhs,
//                            Executor& exec)
//    {
//        return exec.OnError(lhs, rhs);
//    }
//};


//template<
//    class Executor,
//    class BaseLhs,
//    class TypesLhs,
//    int IndexLhs,
//    class BaseRhs,
//    typename ResultType
//>
//class StaticDispatcher<Executor, BaseLhs, TypesLhs, IndexLhs,
//        BaseRhs, NullType, 0, ResultType>
//{
//public:
//    static ResultType Go(BaseLhs& lhs, BaseRhs& rhs, Executor exec)
//    {
//        return exec.OnError(lhs, rhs);
//    }
//};





#endif // __STATICDISPATCHER_HH__
