// template on lecture

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
T maximum(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <class DATA> // Data 是自己定义的？ 的确是 （泛型而已
class BSTNode
{
public:
    BSTNode<DATA> *left;
    BSTNode<DATA> *right;
    BSTNode<DATA> *parent;
    DATA const data;
    BSTNode(const DATA &d) : data(d) 
    {
        left = right = parent = nullptr;
    }
};

int main(int argc, char const *argv[])
{
    cout << maximum<int>(42, 43) << endl;
    cout << maximum(42.1, 43.2) << endl; // compiler can figure out the <double>
    cout << maximum<string>("foo", "bar") << endl;

    // BSTNode n1(10); // requires <int> OR -std=c++17
    BSTNode<int> n2(10);

    // BSTNode* nodePtr;
    BSTNode<int> *nodePtr = new BSTNode<int>(42);
    //auto nodePtr3 = new BSTNode<int>(42);
    // auto nodePtr2 = new BSTNode(42); // also works with -std=c++17 

    return 0;
}