// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;
using std::endl;

// copy constructor
IntList::IntList(const IntList& source) {  // append()?
    Node *s = source.first;
    first = new Node;  // Remember how: a pointer -> a new obj.🍺
    Node *f = first;
    while(s->next){ 
        f->info = s->info;
        f->next = new Node;
        f = f->next;
        s = s->next;
    }
    f->next = NULL;
    f->info = s->info; // 只能默认source指的不是NULL
}

// destructor deletes all nodes
IntList::~IntList() {

    Node *d,*n;
    d = first;
    while(d){  // delete iteratively 
        n = d->next;
        delete d;  // free() solwer and no destructor
        d = n;
    }
    cout << "deleted!!" << endl;
}
    /*
    delte recursively:

IntList::~IntList(){
    Node *p = first;
    delete_helper2(p);
}
    
    
    */

// return sum of values in list
int IntList::sum() const {
    if(this->count()==0) return 0;
    Node* n = first;
    int sum = 0;
    if(n->next == 0) return 0;
    while(n->next){
        sum+=n->info;
        n = n->next;
    }
    sum+=n->info;
    return sum; 
     

}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if(this->count()==0) return false;
    Node *n = first;
    while(n->next != 0){
        if(n->info == value) return true;
        n = n->next;
    }
    if(n->info == value) return true;
    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(this->count()==0) return 0;
    int max = 0;
    Node *n = first;
    while(n->next){
        if(n->info > max) max = n->info;
        n = n->next;
    }
    if(n->info > max) max = n->info;
    return max; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const { 
    int sum = this->sum();// forgot point: this: a pointer. need "->" not "." NOT JAVA!
    int count = this->count();
    if(sum == 0) return 0;
    double avg = (double)sum/count;
    return avg; 
    
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node *n = first;
    first = new Node;
    first->info = value;
    first->next = n;

}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){  // delete the whole shit & append the new values.
    // this->~IntList(); ?

    while(first){
        this->delete_helper1();  // 可省略this
    }
    
    Node *n = source.first;
    while(n!=NULL){
        this->append(n->info);  // 可省略this
        n = n->next;
    }
    
    return *this;
}

// HELPER FUNCTIONS HERE: delete_helper1 and delete_helper2(recursive)
void IntList::delete_helper1(){
    Node *n = (first->next);
    delete first;  // delete 到底会不会删除first? 不会删除指针，但如果指针在对象里的话会把此对象删除。
    first = n;
    
}
void IntList::delete_helper2(Node* p){ // RECURSIVE
    if(p == 0) return;
    if(p->next == 0){
        delete p;
        return;
    }
    delete_helper2(p->next);
    delete p;
    return;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}

