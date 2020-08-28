//
//  Dice.h
//  Dice
//
//  Created by Howard Stahl on 2/16/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#ifndef DICE_H
#define DICE_H
#include "Die.h"

namespace cs31
{
    
    
class Dice
{
public:
    Dice( );
    Dice( int die1, int die2 );
    
    
    void roll();
    int  getDie1( ) const;
    int  getDie2( ) const;
    int  getTotal( ) const;
    
private:
    Die mDie1, mDie2;
};
    
}

#endif /* Dice_hpp */
