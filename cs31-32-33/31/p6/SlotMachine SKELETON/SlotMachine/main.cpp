// slotmachine.cpp

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  
// As you finish implementing each TODO: item, remove its TODO: comment.

#include "SlotMachine.h"
#include "Bank.h"
#include "PayTable.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;



int main()
{
    Bank bank;
    SlotMachine s;
    
    using namespace std;

           // test code
           Bank b;
           assert( b.balance() == 0 );
           assert( b.getWager() == 0 );
           assert( !b.canWager( 100 ) );
           b.deposit( 50 );
           assert( b.balance() == 50 );
           assert( !b.canWager( 100 ) );
           assert( b.canWager( 50 ) );
           b.deposit( 50 );

           b.deposit(100);
           assert(b.balance() == 200);
           b.win(100);
           assert(b.cashOut() == 300);
           b.deposit(100);

           PayTable p( 'A', 'A', 'A' );
           PayTable::Multiplier m = p.calculateMultiplier( );  // 3 Aces is a 10-1 winner
           assert( m == PayTable::Multiplier::TENTIME );
           PayTable p1('1', '2', '3');
           PayTable::Multiplier m1 = p.calculateMultiplier( ); 
           assert( m1 = PayTable::Multiplier::ZERO);
           

           SlotMachine sl( "AKQJ987" );   // cheating...
           b.setWager( 100 );
           s.play( b, 'A', 'A', 'A' );
           assert( b.balance( ) == 1100 );               // 3 Aces is 10-1 winner and a round of play adjusts the bank 

Bank b1(100);
b1.deposit( 50.00 );
b1.win( 50.00 );
b1.cashOut( );
if (b1.canWager( 10.00 ))  
   b1.setWager( 10.00 );
assert(b1.balance() == 0);
b1.setWager( 10.00 );
b1.win( 20.00 );
assert(b1.getWager() == 0);

SlotMachine s1( "ABCDEFG" );
s1.noDisplay();
b1.setWager( 10.00 );
s1.play( b1, 'A', 'B', 'C' );
cout << "wheel3: " << s1.getWheel3() << endl;

Bank b6( 100.00 );
s1.noDisplay();
b6.setWager( 100.00 );
s1.play( b6, 'D', 'E', 'F' );
cout << "b6 balance: " << b6.balance() << endl;
b6.win(100);
cout << "b6 balance after win: " << b6.balance() << endl;

s1.noDisplay();
b6.setWager( 100.00 );
s1.play( b6, 'A', 'B', 'C' );


           cout << "all tests passed!" << endl;
    do
    {
         cout << endl;
         cout << "Move (d#/b#/p/c/q): ";
         string action;
         string message;
         int amount;
         getline(cin,action);
         if (action.size() == 0)
         {
             return( 0 );
         }
         else
         {
             switch (action[0])
             {
                 default:   // if bad move, nothing happens
                     cout << '\a' << endl;  // beep
                     continue;
                 case 'q':
                     return( 0 );
                     break;
                     
                 case 'b':  // get
                     amount = atoi( action.substr(1).c_str() );
                     if (amount == 0)
                         amount = 1;
                     if (bank.canWager(amount))
                     {
                         bank.setWager(amount);
                         cout << "$" << amount << " Bet Accepted!" << endl;
                     }
                     else
                     {
                         cout << "Invalid Bet" << endl;
                     }
                     break;
                 case 'p':
                     if (bank.getWager() == 0)
                     {
                         cout << "You Must Bet First Before Playing" << endl;
                     }
                     else
                     {
                         s.play( bank );
                     }
                     break;
                 case 'd':
                     amount = atoi( action.substr(1).c_str() );
                     if (amount == 0)
                     {
                         cout << "Invalid Bank Deposit" << endl;
                     }
                     else
                     {
                         bank.deposit( amount );
                         cout << "$" << bank.balance() << " Available To Bet" << endl;
                     }
                     break;
                 case 'c':
                     amount = bank.cashOut();
                     cout << "$" << amount << " Returned To You!" << endl;
                     amount = 0;
                     break;
             }
         }
         
    } while ( true );
    
    return( 0 );
}

