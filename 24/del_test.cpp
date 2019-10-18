#include <iostream>
using namespace std;

class C{
public:	void f(){cout << "f" << endl;}
};

int main(){
	C *c1 = new C;
	C c2;

	c2.f();
	c1 = &c2;
	cout << "next, delete" << endl; // delete用在指针
	delete &c2;   // delete c1 的话对象会直接被删掉 delete &c2 同理由。不可以delete c2
	c1->f();

	return 0; 

}
