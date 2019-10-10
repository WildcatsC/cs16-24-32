// a .h file is a header file
// it includes declarations, but not implementations

// these fancy things here and the end of the file make
// sure that you can't #include the file more than once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class llist{
public:
	llist();
	llist(const llist& other);
	
	void append(int x); // 在链表尾部加上x，让下面的info=x
	void print();	    // *
	vector<int> vectorize() const; //list to vector, remember to #inclue <vector>

	bool operator==(const llist& other) const; //? 

private:   // 一个llist object🈶两个Node structure.
	struct Node{
		int info;
		Node* next;
	};
	
	Node* head;  // pointer to the head part of node
	Node* tail;  // pointer to the tail part of node
};


#endif 
