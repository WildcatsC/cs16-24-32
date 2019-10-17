// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    Node *s = source.first;//IMPLEMENT THIS
    first = new Node;  // Remember how: a pointer -> a new obj.🍺
    Node *f = first;
    while(s->next){ 
        f->info = s->info;
        f->next = new Node;
        f = f->next;
        s = s->next;
    }
    f->next = NULL;
    f->info = s->info;
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    Node *d,*n;
    d = first;
    while(d){
        n = d->next;
        free(d);
        d = n;
    }
}


// return sum of values in list
int IntList::sum() const {
    Node* n = first;
    int sum = 0;
    if(n->next == 0) return 0;
    while(n->next){
        sum+=n->info;
        n = n->next;
    }
    sum+=n->info;
    return sum; 
     
     // REPLACE THIS NON-SOLUTION

}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first;
    while(n->next != 0){
        if(n->info == value) return true;
        n = n->next;
    }
    if(n->info == value) return true;
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    Node *n = first;
    while(n->next){
        if(n->info > max) max = n->info;
        n = n->next;
    }
    if(n->info > max) max = n->info;
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const { 
    int sum = this->sum();// forgot point: this: a pointer. need "->" not "." NOT JAVA!
    int count = this->count();
    double avg = (double)sum/count;
    return avg; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node *n = first;
    // IMPLEMENT
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
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
