#include <iostream>
#include <string>
using namespace std;

int t(string k){
	for(size_t i; i<k.size(); i++){
		cout << i << endl;
		cout << k[i] << endl;
	}
	return 0;
}

int ctoi(char c){
    int r = (int)c - 48;
    if(r >= 0 && r <= 9) return r;
    return -1;
}

void ref(int &a){
	a++;
	cout <<"ref: " << a << endl;
	}
void val(int a){
	a++;
	cout <<"val: " << a << endl;
}


void foo( int a, string d = "" );
void foo( int a);
void foo( double a);

int main(int argc, const char * argv[]) {
    
    int x[] = {1};
    //double r = (double)1/x;
    int r[] = {2};
    int a = 1;
    int b = 1.5;
    int* p;
    p = r;
    //cout << *p << endl;
    foo(b);
    
}

void foo(int a, string d){
    cout << 1;
}

void foo(int a){
    cout << 2;
}

void foo(double a){
    cout  << 3;
}
