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


int main(){
	int i = 12, j = 10, k = 0;
	k = i++ * --j;
	cout << k << endl;
	k = --i + ++j;
	cout << k << endl;	
	return 0;
}
