//
//  main.cpp
//  DayOfYearExample
//
//  Created by Howard Stahl on 1/19/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#include <iostream>
#include "DayOfYear.h"
using namespace std;

int main(int argc, const char * argv[]) {
    DayOfYear today;
    today.input();
    today.output();
    
    return 0;
}
