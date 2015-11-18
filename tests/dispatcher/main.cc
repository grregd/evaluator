
#include <iostream>

#include <gtest/gtest.h>

#include <staticdispatcher.hh>

using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
};

class Rectangle: public Shape
{
};


class Ellipse: public Shape
{

};

class Poly: public Shape
{

};


class HatchingExecutor
{
public:
    // Various intersection algorithms
    int Fire(Rectangle&, Rectangle&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    int Fire(Rectangle&, Ellipse&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    int Fire(Rectangle&, Poly&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    int Fire(Ellipse&, Poly&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    int Fire(Ellipse&, Ellipse&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    int Fire(Ellipse&, Rectangle&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    int Fire(Poly&, Poly&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    int Fire(Poly&, Rectangle&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    int Fire(Poly&, Ellipse&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    // Error handling routine
    int OnError(Shape&, Shape&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

typedef std::tuple<Rectangle, Ellipse, Poly> TypesTupleLhs;
typedef std::tuple<Rectangle, Ellipse, Poly> TypesTupleRhs;

typedef StaticDispatcher < HatchingExecutor,
                           Shape, TypesTupleLhs, std::tuple_size<TypesTupleLhs>::value,
                           Shape, TypesTupleRhs, std::tuple_size<TypesTupleRhs>::value,
                           int
                         > Dispatcher;



TEST( StaticDispatcherTest, basic )
{
    {
        Dispatcher lD;
        Shape *p1 = new Shape();
        Shape *p2 = new Shape();

        lD.Go( *p1, *p2, HatchingExecutor() );
    }

    {
        Dispatcher d1;
//        Shape *p1 = new Ellipse;
//        Shape *p2 = new Ellipse;

//        d1.Go( *p1, *p2, HatchingExecutor() );
    }
}
