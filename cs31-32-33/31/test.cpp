#include <iostream>
#include <cmath>
using namespace std;

//void foo( int a, string d = "" );
int foo( int a);
double foo( double a = 2.5);
int foo(int a, string d = "");

int main(int argc, const char * argv[]) {
    
    int x[] = {1};
    //double r = (double)1/x;
    int r[] = {2};
    int a = 1;
    int b = 2.5;
    int* p;
    p = r;
    //cout << *p << endl;
    int s = foo();
    cout << s << endl;
    cout << "hello" ;
    
}

//void foo(int a, string d){
//    cout << 1;
//}

int foo(int a){
    return 1;
}

double foo(double a){
    return 22;
}
int foo(int a, string d){
    return 3;
}