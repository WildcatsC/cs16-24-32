//
//  DayOfYear.cpp
//  DayOfYearExample
//
//  Created by Howard Stahl on 1/19/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#include "DayOfYear.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin  >> month;
    cout << "Enter the day of the month: ";
    cin  >> day;
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        cout << "Illegal date!  Program terminated" << endl;
        exit( 1 );
    }
}

void DayOfYear::output()
{
    switch( month )
    {
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11:
            cout << "November ";
            break;
        case 12:
            cout << "December ";
            break;
        default:
            cout << "Error in DayOfYear::output.";
    }
    cout << day << endl;
}