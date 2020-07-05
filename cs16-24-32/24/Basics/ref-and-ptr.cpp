#include <iostream>
#include <cmath>
using namespace std;

struct N{public:int k;
};

int main(){
	N* p = new N;
	N q;

	p->k = 1;
	q.k = 2;

	cout << p->k << endl;
	cout << q.k << endl;
	return 0;
}
