// This program demonstrates how to make use of existing objects.
// This program uses a bankAccount class with the interface described
// in class.

#include <iostream>                // for std::cout
#include <string>			     // for string class
#include "Baccount.h"              // for bankAccount class
using namespace std;               // supports cout

int main( )
{
  string name;
  double openingbalance;

  cout.setf( ios::fixed ); 
  cout.setf( ios::showpoint );
  cout.precision( 2 );

  cout << endl << endl << "\t\tWelcome to Howie's Bank!" << endl;
  cout << "Your Wish Is My Command!" << endl;
  cout << "Please enter your name and opening bank balance: ";
  cin  >> name >> openingbalance;
 
  bankAccount account;
  account.setName( name );
  account.deposit( openingbalance );
 
  cout << "Thank You For Banking With Howie's Bank!" << endl;
  cout << account.name() << " has a balance of $" << account.balance();
  cout << endl << endl;
  
  return 0;
}
  
