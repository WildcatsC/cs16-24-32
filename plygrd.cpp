#include <iostream>
using namespace std;

class L{
public:
	L(int k):k(k){ cout << "initialize!" << endl;}

	void func1(){
		cout << "f1" << endl;
	}
	void func2(){
		this->func1();
	}	
	int k;

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
    cout << "&z.b = " << &z.b << endl;                          // 0x7ffee07c1704
    cout << "&z.c = " << reinterpret_cast<void*>(&z.c) << endl; // 0x7ffee07c1708
    cout << "&z.d = " << &z.d << endl;                          // 0x7ffee07c1710
}

//int main(){
	// L *l;
	// l = new L;
	// l->func2();
<<<<<<< HEAD
//	L k(100);
//	cout << k.k << endl;
//	return 0;

//}
=======
	L k(100);
	cout << k.k << endl;
	return 0;
}
>>>>>>> 42e3e37c31a6407b0dc4a686f81d05b3d0e0b135
