// implementation file!

// single quotes because this is in the current directory
// (i.e., LinkedList.h is not a standard library)
#include "LinkedList.h"
#include <iostream>
#include <vector>
using namespace std;

// an empty linked list has NULL head and tail pointers!
// let's set that up properly!
LinkedList::LinkedList() : head(nullptr), tail(0) {}

LinkedList::LinkedList(const LinkedList &other) : 
head(other.head), tail(other.tail) {
    // default behavior is the above

    // this isn't good! We should copy any of the elements
    // so that if we delete on in our linked list, it doesn't affect
    // the linked list that we copied from!

    // Correct solution:
    // iterate through the linked list you want to copy.
    // append each value you see to the list you're building
    // in this constructor.
}

LinkedList& LinkedList::operator=(const LinkedList &other) {
    // default behavior is this:
    head = other.head;
    tail = other.tail;

    // this isn't good! We should copy any of the elements
    // so that if we delete on in our linked list, it doesn't affect
    // the linked list that we copied from!

    // Correct solution:
    // Delete all our current nodes first!
    // Iterate through the linked list you want to assign.
    // Append each value you see to ourselves.
}


void LinkedList::append(int x) {
    // make a new Node (on the heap!)
    Node *n = new Node;
    n->info = x;
    n->next = nullptr;

    // add it to the end of the current linked list
    if (head == nullptr && tail == nullptr) {
        // empty list! n is the only node.
        head = n;
        tail = n;
    } else {
        // non-empty list; let's add to the last element
        tail->next = n;
        tail = n;
    }
}

bool LinkedList::operator==(const LinkedList &other) const {
    return false; // Stub -- compiles, but not the correct implementation
}

vector<int> LinkedList::vectorize() const {
    vector<int> ret;

    Node *n = head;
    while (n != nullptr) {
        // n->info is shorthand for (*n).info
        ret.push_back(n->info);
        n = n->next;
    }

    return ret;
}

void LinkedList::print() const {
    Node *n = head;
    while (n != nullptr) {
        // n->info is shorthand for (*n).info
        cout << n->info << " ";
        n = n->next;
    }
    cout << endl;
}