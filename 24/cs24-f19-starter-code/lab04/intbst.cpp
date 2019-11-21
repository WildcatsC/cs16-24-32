// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE
/*
 
 ** 二叉树的一些实现  打印方法用 recursive 最方便   

*/

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    // IMPLEMENT HERE
    if(n){
        printInOrder(n->left);
        cout << n->info << " ";
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    // IMPLEMENT HERE
    if(n){
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " "; 
    }
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    //cout<<n->info<<endl;
    if(n){
        if(n->left == 0 && n->right == 0) return n->info;
        else{
            int left = sum(n->left);
            int right = sum(n->right);
            return n->info + left +right;
        }
    }
    return 0; // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(n){
        if(n->left == 0 && n-> right == 0) return 1;
        else{
            int left = count(n->left);
            int right = count(n->right);
            return left+right+1;
        }
    }
    return 0; // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {

    if(root == 0) return false;

    Node* pt;
    pt = root; 

    while(pt->info!=value){
        if(pt->left == 0 && pt->right == 0) return false; 

        (value < pt->info)? pt = pt->left : pt = pt->right;

        if(!pt) return false;
    }
    
    return true; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{

    if(contains(value)){
        Node* result = root; 

        while(result->info!=value ){
            (result->info < value)? result = result->right : result = result->left;
        }

        return result;
    }
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    
    if(getPredecessorNode(value)){
        
        Node* p = getPredecessorNode(value);
        Node* l = p;

        if(l->left){    // check if it has left 
            l = l->left;
            while(l->right){   // find left largest
                l = l->right;
            }
        }

        if(p->parent){  // check if is has parent 
            p = p->parent;
            if(p->right == l) return p->info; // confirm it has no left and is a right child

            while(p->parent && p->parent->left == p){ // go up with all left branches
                p=p->parent;
            }
            
            if(p->parent && p->parent->right == p) return p->parent->info;
        }

        return l->info;
    }
    return 0;
     // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    if(getPredecessorNode(value)){
        
        Node* p = getPredecessorNode(value);
        Node* r = p;

        if(r->right){    
            r = r->right;
            while(r->left){   
                r = r->left;
            }
        }

        if(p->parent){  // check if is has parent 
            p = p->parent;
            if(p->left == r) return p->info; 

            while(p->parent && p->parent->right == p){ 
                p=p->parent;
            }
            
            if(p->parent && p->parent->left == p) return p->parent->info;
        }

        return r->info;
    }
    return 0; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    if(contains(value)){
        


    }
    return false; // REPLACE THIS NON-SOLUTION
}
