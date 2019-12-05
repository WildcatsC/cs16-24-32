// usestack.cpp - for CS 24 lab practice using stacks
// NAME(S), DATE

#include "intstack.h"
#include <iostream>
using namespace std;

int profix(){
    Stack numbers; 


}
int main(int argc, char* argv[]) {
    Stack s;
    cout<<argv[1]<<endl; 

    s.push(10);
    s.push(20);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
