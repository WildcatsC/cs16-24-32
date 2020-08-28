//
//  Dice.cpp
//  Dice
//
//  Created by Howard Stahl on 2/16/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//
#include <iostream>
#include <stdexcept>
#include "Dice.h"
#include "RandomNumber.h"


namespace cs31
{
    
Dice::Dice( )
{
    mDie1 = Die( 1 );
    mDie2 = Die( 1 );
}
    
Dice::Dice( int die1, int die2 )
{
	using namespace std;

    mDie1 = Die( die1 );
    mDie2 = Die( die2 );
}
    
    
void Dice::roll()
{
    mDie1.roll( );
    mDie2.roll( );
}
    
int  Dice::getDie1( ) const
{
	return( mDie1.getDie( ) );
}
    
int  Dice::getDie2( ) const
{
	return( mDie2.getDie( ) );
}
    
int  Dice::getTotal( ) const
{
    return( getDie1( ) + getDie2( ) );
}
    
    
    
}