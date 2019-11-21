#include <iostream>
using namespace std;

void m(){cout << "m" << endl;}

int main(){
	m();
	int *p;
	*p = 1;
	int *q = p;
	cout << *q << endl;
	return 0;
}
