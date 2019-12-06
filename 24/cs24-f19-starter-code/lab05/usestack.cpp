// usestack.cpp - for CS 24 lab practice using stacks
// NAME(S), DATE

#include "intstack.h"
#include <iostream>
using namespace std;

int profix(){   //   profix algorithm
    Stack numbers; 
    
    return 0; 
}

int main(int argc, char* argv[]){   // 遗漏小知识点  char** argv and char* argv[]
    Stack s;

    cout<< (int)argv[0] <<endl; 

    s.push(10);
    s.push(20);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    cout << " == == == " << endl;

    return 0;
}
