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


int main(){
	// L *l;
	// l = new L;
	// l->func2();
	L k(100);
	cout << k.k << endl;
	return 0;

}
