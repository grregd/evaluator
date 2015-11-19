// infix2postfix_Dijkstra.cpp : Defines the entry point for the console application.
//

//
// Edsger Dijkstra invented the Shunting-yard algorithm to convert infix expressions to postfix (RPN).
//
// http://scriptasylum.com/tutorials/infix_postfix/algorithms/infix-postfix/index.htm
// http://everything2.com/title/Infix+to+postfix+conversion+algorithm

#include <memory>
#include <algorithm>
#include <functional>
#include <string>
#include <stack>
#include <list>
#include <iostream>
#include <sstream>

//#include "exprtoken.hh"
//#include "operands.hh"
//#include "operations.hh"
#include <evaluators.hh>
#include <Factory.hh>


using namespace std;
using namespace Operands;
using namespace Operations;
using namespace Evaluators;




//inline int cmpprecedence( const char op1, const char op2 )
//{
//    //if (op1 == op2 ||
//    //    (op1 == '+' && op2 == '-' || op1 == '-' && op2 == '+'))
//    //    return 0; // op1 == op2
//    if ((op1 == '+' || op1 == '-') &&
//        (op2 == '*' || op2 == '/' || op3 == '^'))
//        return -1; // op1 < op2
//    else if ((op1 == '*' || op1 == '/') &&
//        (op2 == '+' || op2 == '-'))
//        return 1;  // op1 > op2
//
//    return 0;
//}




int main(int argc, char **argv )
{

    {
        std::string lExpression("1 + 2 + 3");
        stringstream lPostfix;
        Factory().transform( lPostfix, lExpression );
        std::cout << lExpression << " --> " << lPostfix.str() << " --> " << Factory().eval( lPostfix ) << std::endl;
    }


    ExpressionTokensStack     lStack;
    stringstream lStrStream( "+ + 1.09991 1.1 2" );
    std::string lTok;
    while ( ! (lTok = Factory::nextStrToken( lStrStream )).empty() )
    {
        std::cout << "lTok: '" << lTok << "'" << std::endl;
        lStack.push( Factory::createToken( lTok ) );
    }



    Evaluator lEvaluator;
    Evaluators::evaluate( lStack, lEvaluator );
    std::cout << lStack.size() << std::endl;
    std::cout << lEvaluator.getOperandsStack().size() << std::endl;
    if ( Numeric::Ptr lValue = std::dynamic_pointer_cast< Numeric >( lEvaluator.getOperandsStack().top() ) )
    {
        std::cout << lValue->getValue() << std::endl;
    }


    string lInfix;

    while (cin >> lInfix)
    {
        string inf;
        stringstream lPostfix;
        Factory().transform( lPostfix, lInfix );
        string t = lPostfix.str();
        //t.resize(infix.pcount());
        //cout << t << endl;
        cout << Factory().eval( lPostfix ) << endl;
    }

    return 0;
}

