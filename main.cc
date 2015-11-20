
#include <Factory.hh>


#include <string>
#include <iostream>
#include <sstream>


using namespace std;


int main(int argc, char **argv )
{
    string lInfix;

    while ( std::getline( cin, lInfix ) )
    {
        cout << Factory::evalExpression( lInfix ) << endl;
    }

    return 0;
}

