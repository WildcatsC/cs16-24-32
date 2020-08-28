#include <iostream>
#include "RandomNumber.h"
#include "Dice.h"
#include <stdexcept>


int main( ) 
{
    using namespace std;
    using namespace cs31;
    
    Dice d;
    for (int i = 0; i <= 20; i++)
    {
        d.roll();
        cout << d.getTotal() << endl;
    }
    

/*
    try 
	{
		d = Dice( -1, -1 );
		cout << d.getTotal() << endl;
	} 
	catch( std::logic_error variable )
	{
		cout << "caught a logic_error!" << endl;
		cout << variable.what( ) << endl;
	}
	catch( ... )
	{

	}
*/

	return( 0 );
}
