#include <iostream>
using namespace std;

class Link{
public:
	int head; 
	Link* tail;
	~Link(){cout<<"already destructed the temp_obj!"<<endl;}	
};

int main(){
	Link *first = new Link;
	first->head = 1;
	Link *second = new Link;
	first->tail = second;
	second->head = 2;
	second->tail = NULL;

	cout << first->head << " " << second->head << endl;
	Link temp_obj;  // on the stack? so it would be destruct defaultly.
	Link* temp = second;
	first->tail = &temp_obj;
	second->tail = first;
	first->tail = NULL; 
//	delete &temp_obj;
	cout << second->head << " " << first->head <<endl;
	cout << "yes you did it" << endl;
	return 0; 

}
