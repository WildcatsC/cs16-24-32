#include <iostream>
using namespace std;

class test{

public: 
	int init1;
	int cp1;
			
	test(int val){
		init1 = val;
		cout << "constructor!" << endl;
		cout << "init1 = " <<  init1 << endl; 
	}
	~test(){cout<<"destruct!"<<endl;} // destructor 
		
	test(const test& other){
		cp1 = other.init1;
		cout << "copy constructor!" << endl;
		cout << "cp1 = " << cp1 << endl;		
	}	// In main(): test con(value);  ==  constructor
		//			  test cp(con); ==  copy constructor 只需要已有的object的值
		//			  test ca; ca = con;  == copy assignment
};

class test2{
	public:
	int a;
	int b;
	int random;

	test2(int aval, int bval):a(aval),b(bval),random(10){
		cout<<"init list! " <<endl;}

};  // 此为initialization list, 和上面test的initialize方法等价



int main(){
	test con(10);
	test cp(con);
	//test obj_ref(10,7);   // main return后会被destruct
	//test* obj = new test(10,7);  // 不会被destruct！
	return 0;
}
