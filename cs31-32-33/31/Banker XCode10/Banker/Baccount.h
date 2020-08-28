//------------------------------------------------------------------
// INTERFACE FILE: baccount.h
//
// Defines class bankAccount
//
//-------------------------------------------------------------------
// SAFEGUARDS AND INCLUDES
#ifndef BACCOUNT_H   // Avoid redeclaring class bankAccount.
#define BACCOUNT_H   // This code is compiled only once
#include <string>    // for class string
using namespace std; 

///////////////////////////////////////////
/////// class bankAccount defintion ///////
///////////////////////////////////////////

class bankAccount {
public:  // class member functions

//--constructors
	bankAccount();

	bankAccount(string initName, double initBalance);
	// post: A bankAccount with two arguments when called like this:
	//       bankAccount anAcct("Hall", 100.00);

//--modifiers

	void deposit(double depositAmount);
	// post: depositAmount is credited to this object's balance

	void withdraw(double withdrawalAmount);
	// post: withdrawalAmount is debited from this object's balance

//--accessors
	
	double balance() const;
	// post: return this account's current balance

	string name() const;
    // post return the account name

	void setName( string initName );
	// post updates the member variable my_name

private: 
	string my_name;    // Uniquely identify an object
	double my_balance; // Store the current balance
};

#endif   // ifndef BACCOUNT_H
