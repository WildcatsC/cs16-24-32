//
//  Bank.cpp
//  SlotMachine
//
//

#include "Bank.h"


// The purpose of this class is to 
// implement a bank of funds and a wager than can be won or lost
Bank::Bank( int amount )
{
    bankAmount = amount;
    wager = 0;
}
    
// TODO: adjust the bank balance for the amount won or lost
void Bank::win( int amount ){
    bankAmount += amount; // add to the balance and set the wager to zero
    wager = 0;
}
    
// TODO: adjust the bank balance for the amount won or lost
void Bank::lose( int amount )
{
    bankAmount -= amount;  // subtract from the balance and set the wager to zero
    wager = 0;
}

// TODO: adjust the bank balance for the amount being added to the bank
void Bank::deposit( int amount )
{
   bankAmount += amount;// add to the balance
}
 
// trivial getter
int Bank::balance() const
{
    return( bankAmount );
}
    
// TODO: return the bank balance and set it bank to zero
int Bank::cashOut( )
{
    int temp = balance();// return the balance
    bankAmount = 0;// set both the wager and the balance to zero
    wager = 0;// for now...
    return( temp );
}

// TODO: can the amount be wagered??
bool Bank::canWager( int amount ) const
{
    if(amount <= bankAmount)// can the bank balance allow this amount to be wagered??
        return true;
    // for now...
    return( false );
}
    
// trivial setter
void Bank::setWager( int amount )
{
    wager = amount;
}
 
// trivial getter
int Bank::getWager() const
{
    return( wager );
}
