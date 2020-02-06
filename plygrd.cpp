#include <iostream>
using namespace std;

class L{
private:
	int k,l;
public:
	L(){
	cout << "default:" << endl;
	this->k = 1;
	this->l = 2;
	}

	L(int k, int l):k(k),l(l){ 
	cout << "k:" << k << endl;
	cout << "l:" << l << endl;
	int t = k;
	k = l; 
	l = t;
	cout << "k:" << k << endl;
	cout << "l:" << l << endl;
	cout << "not default initialize!" << endl;
	}

	void func1(){
		cout << "f1" << endl;
		cout << this->k << endl;
	}
	void func2(){
		this->func1();
	}	

};

class Z {
    public:
    char a;     // 1 byte
    int b;      // 4
	long d;
    char c;     // 1
    //double d;   // 8
};

int main() {
    Z z;
    cout << sizeof(z) << endl;                                  // 24
    cout << "&z = " << &z << endl;                              // 0x7ffee07c1700
    cout << "&z.a = " << reinterpret_cast<void*>(&z.a) << endl; // 0x7ffee07c1700
// char shoud use reinterpret cast to print
    cout << "&z.b = " << &z.b << endl;                          // 0x7ffee07c1704
    cout << "&z.c = " << reinterpret_cast<void*>(&z.c) << endl; // 0x7ffee07c1708
    cout << "&z.d = " << &z.d << endl;                          // 0x7ffee07c1710

  	cout << "=====" << endl;

	int* a;
	a = new int[100];
	for(int i = 0; i<4; i++) a[i]=i;
	cout << a[0]<<a[1]<<a[2]<<a[3] << endl;
	cout << (a+1)[0] << endl;

	cout << "===" << endl;
	L *l;
	l = new L();
	l->func1();
	l = new L(3,4);
	l->func1();
	return 0;
}
