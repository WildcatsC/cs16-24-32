//
//  Die.h
//  Die
//
//  Created by Howard Stahl on 2/16/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#ifndef DIE_H
#define DIE_H

namespace cs31
{
    
    
class Die
{
public:
    Die( );
	Die( int value );
    
    void roll();
    int  getDie( ) const;
    
private:
    int mValue;
};
    
}

#endif /* Die_hpp */
