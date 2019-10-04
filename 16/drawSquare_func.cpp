// to run the program, you have to do: ./drawSquare_func n(a number)

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

/*
 知识点 commandline argument:
       argc == argument count
            is int and stores number of command-line arguments passed by the user including the name of the program.
       argv == argument vector
            is array of character pointers listing all the arguments. (space 隔开每个 argument)

 这里先用 assertTrue 验证了有多少个 argument，不符合条件就 cerr (Standard output stream for errors)
 没有这个检验的话，argument 数量不匹配的时候就会出现 segmentation fault 😅😅😅
 
 */


void drawSquare(int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            // this loop will execute n times
            cout << "* ";
        }
        // finish the line, then print a newline
        cout << "\n";
    }

}

void assertTrue(bool b) {
    // if b is true, let the program continue,
    // otherwise end the program here
    if (b) {
        // do nothing
    } else {
        // stop the program, because b was false
        cerr << "Assertion failed!\n";
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    /* 
    // assert takes a boolean-valued expression
    // if true, it lets continue, otherwise it stops the program with an error
    assert(argc == 2); // this makes sure that I have 1 command-line argument
    // it will stop the program if it isn't there
    */

    // the code above is essentially the same as:
    /*
    if (argc != 2) {
        cerr << "Assertion failed\n";
        exit(1); // end the program
    }
     */

    // or, with our own assertTrue function:
    assertTrue(argc == 2);

    int n = atoi(argv[1]);

    drawSquare(n); // this will print a nxn square

    return 0;
}
