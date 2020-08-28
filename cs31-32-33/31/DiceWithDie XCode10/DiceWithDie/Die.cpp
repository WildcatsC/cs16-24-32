//
//  Die.cpp
//  Die
//
//  Created by Howard Stahl on 2/16/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//
#include <iostream>
#include <stdexcept>
#include "Die.h"
#include "RandomNumber.h"


namespace cs31
{
    
Die::Die( )
{
    mValue = 1;
}

Die::Die( int value )
{
	using namespace std;

    mValue = value;
	if (mValue < 1 || mValue > 6)
	{
		cerr << "die is invalid..." << endl;
		// throw an exception...
		logic_error le( "die is invalid!");
		throw( le );
	}
}
    
void Die::roll()
{
    RandomNumber r( 1, 6 );
    mValue = r.random();
}
    
int  Die::getDie( ) const
{
    return( mValue );
}    
    
    
}