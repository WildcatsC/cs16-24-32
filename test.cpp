#include <iostream>
using namespace std;

class L{
public:
	void func1(){
		cout << "f1" << endl;
	}
	void func2(){
		this->func1();
	}	


};


int main(){
	L *l;
	l = new L;
	l->func2();
	return 0;

}
