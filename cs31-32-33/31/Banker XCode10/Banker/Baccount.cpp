//--------------------------------------------------------------------
// IMPLEMENTATION FILE: baccount.cpp
//
// Implements 1. class bankAccount member functions
//
//--------------------------------------------------------------------
#include "Baccount.h"  // allows for separate compilation if you want
#include <iostream>    // for ostream << and istream >>
#include <string>      // for class string
using namespace std;

//--constructors

bankAccount::bankAccount()
{ 
  my_name = "?name?";
  my_balance = 0.0;
}

bankAccount::bankAccount(string initName, double initBalance)
{
  my_name = initName;
  my_balance = initBalance;
}

//--modifiers

void bankAccount::deposit(double depositAmount)
{
  my_balance = my_balance + depositAmount;
}

void bankAccount::withdraw(double withdrawalAmount)
{
  my_balance = my_balance - withdrawalAmount;
}

//--accessors

double bankAccount::balance() const
{
  return my_balance;
}

string bankAccount::name() const
{
  return my_name;
}

void bankAccount::setName( string initName )
{
  my_name = initName;
}

