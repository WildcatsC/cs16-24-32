/*
    The BIG FOUR 

    1. const method: will not allow it to modify the objects 

*/

#include <iostream> 
#include <cstdlib> 
using namespace std;


class Date{ 

    public:
    
    Date(int mon, int day){
        mm = mon;
        dd = day;
    };                          // will be final after the first init
    
	void setDate(int mon, int day);
    int getMonth() const;  // mon will not be modified  
    int getDay() const;
        

    private:
    
	int mm;    // private objects in Date
    int dd;
}; // c++ class remember the ";"

void Date::setDate(int mon, int day){

    mm = mon;
    dd = day;

}

int main(){
    
    Date today(100000,7);  // convenient way to new an object
    //today.setDate(10,7);
    cout << today.getMonth() << "-" << today.getDay() << endl;

    return 0;
}

int Date::getDay() const{
    return dd;
}

int Date::getMonth() const{
    return mm;
}


void foo(){
    Date p;  // on the stack, destructor is called after foo() returns
    Date *q = new Date;  // on the heap 
}
