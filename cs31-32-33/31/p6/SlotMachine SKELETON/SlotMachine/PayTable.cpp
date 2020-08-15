//
//  PayTable.cpp
//  SlotMachine
//
//

#include "PayTable.h"


PayTable::PayTable( char wheel1, char wheel2, char wheel3 )
{
    mWheel1 = wheel1;
    mWheel2 = wheel2;
    mWheel3 = wheel3;
}

// TODO:  For the wheel combination, determine the pay multiplier
PayTable::Multiplier PayTable::calculateMultiplier( )
{
    // For now...
    Multiplier result = ZERO;
    
    int char_map[150];
    char wheel_list[3];

    for(int i = 0; i < 150; i++)
        char_map[i] = 0;

    wheel_list[0] = mWheel1;
    wheel_list[1] = mWheel2;
    wheel_list[2] = mWheel3;


    for(int i = 0; i < 3; i++){
        int key = 0;
        key = static_cast<int> (wheel_list[i]);
        char_map[key]++;
    }
    
    // 1 Ace:
    if(char_map[65] == 1){
        result = ONETIME;
        for(int i = 0; i < 150; i++){
            if(char_map[i] == 2)
                result = FOURTIME;
            if(char_map[75] == 1 && char_map[81] == 1)
                result = FIVETIME;
        } 
    }
    // 2 Aces:
    if(char_map[65] == 2)
        result = FIVETIME;

    // 3 Aces: 
    if(char_map[65] == 3)
        result = TENTIME;

    // no Ace:
    if(char_map[65] == 0){
        for(int i = 0; i < 150; i++){
            if(char_map[i] == 2)
                result = THREETIME;
            if(char_map[i] == 3)
                result = SEVENTIME;
        }
    }

    
    return( result );
}

// TODO: For the wheel combination and wager of the passed Bank, update the Bank's balance
void PayTable::manageWager( Bank & bank )
{
    // for the wager, adjust the Bank balance based on the pay multiplier
    double amount = bank.getWager();
    Multiplier multiplier = calculateMultiplier();

    // TODO: adjust the bank balance accordingly...

    switch (multiplier)
    {
    case ZERO:
        bank.lose(amount);
        break;
    case ONETIME:
        bank.win(amount);
        break;
    case TWOTIME:
        bank.win(amount*2);
        break;
    case THREETIME:
        bank.win(amount*3);
        break;
    case FOURTIME: 
        bank.win(amount*4);
        break;
    case FIVETIME: 
        bank.win(amount*5);
        break;
    case SIXTIME: 
        bank.win(amount*6);
        break;
    case SEVENTIME: 
        bank.win(amount*7);
        break;
    case TENTIME: 
        bank.win(amount*10);
        break;
    
    default:
        break;
    }

}
