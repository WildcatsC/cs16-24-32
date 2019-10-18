#include <iostream>
using namespace std;

class test{
public:
	int a;
	test(){
	a=1;
	cout << "construct!" << endl;
	}
};

int main(){

cout << "== block0: ==" << endl;

	test t0;  // define了一个test对象，并有一个 &t0 指针指着这个对象
	test *t1; // 空指针！  define了一个test类的指针，并没有指向任何对象
	t1 = &t0; // 现在把 &t 的地址 assign 给了 t1 这个指针,所以指针t1也同时指向了t0对象
	cout << (t1==&t0) << endl; // true 
	
cout << "== block1: ==" << endl;

	// Case in JAVA:  (java 里变量就是指针)
	test *t2;
	t2 = t1; // t2现在已经指向了上面的同一个对象
	t2->a = 10; //直接改变了上面对象里的a
	cout << t0.a << " " << t1->a << endl;  // 输出都是10

cout << "== block2: ==" << endl;
	
	// **important** MEMORY LEAK!
	test *t;
	t = new test; // 指向一个default对象 a=1
	cout << t->a << endl; // 输出1
	t = t2; // 将t指向了t2那个对象，原来t指的那个已经memory leak了无法访问
	cout << t->a << endl; // 输出10，t里原来那个a已经没了

cout<<"== block3: =="<<endl;

	test t3;   
	test t4;  // define了两个对象 注意是两个不同的对象有着不同的指针
	t4 = t3;  // 现在将t3的值assign给了t4
	t4.a = 2; // 此时改变t4内的值不影响t3
	cout << t3.a << endl; // 输出1
	
	return 0;
}
