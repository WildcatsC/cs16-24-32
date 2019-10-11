#include <iostream>
#include <vector>
#include "llist.h"
using namespace std;

llist::llist(): head(NULL),tail(NULL){}

llist::llist(const llist& other){
	head = other.head;
	tail = other.tail;
}

llist::append(int x){
	Node* n = new Node;  // on the heap;
	n->info = NULL;

	if(head == NULL && tail == NULL){ //append 到一个空的llist
		head = n;
		tail = n;	
	}else{
		tail->next = n;
		
	}
}
