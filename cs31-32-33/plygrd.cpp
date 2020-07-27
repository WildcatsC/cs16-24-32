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


void foo( int a, string d = "" );
void foo( int a);
void foo( double a);

int main(int argc, const char * argv[]) {
	cout.setf(ios::boolalpha);
	string s1 = "ABC";
	string s2 = "abc";
	string s3 = "bcd";
	bool b = s1<s2;
	bool c = s2>s3;
	char a1 = '1';
	char a2 = '2';
	cout << "ABC < abc: " << b << endl;
	cout << "abc < bcd: " << c << endl;
	int b1 = (int) a1;
	int b2 = (int) a2;
	int c1 = static_cast<int> (a1);
	int c2 = static_cast<int> (a2);
	cout << "here: " << endl;
	cout << b1  << endl;
	cout << b2  << endl;
	cout << c1 << endl;
	cout << c2 << endl;
	
	cout << "========" << endl;

	char cha = 'X';
	int k = static_cast<int> (cha);
		cout << k  << endl;
	char back = static_cast<char> (k);
		cout << back << endl;
}

void foo(int a, string d){
    cout << 1;
}

void foo(int a){
    cout << 2;
}

void foo(double a){
    cout  << 3;
}
