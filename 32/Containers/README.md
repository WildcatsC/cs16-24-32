There are many implementations of containers.

    *Containers are data abstractions where you can store a sequence of elements. … and iterators…
    *Iterators are a common part of these containers, which allow you to “iterate” through the components
    *Depending on the container, you can even read / write from / to these elements

***

Vector Initialization

push_back() is one way to create elements in a vector. Though it’s not the only way

    *You can declare a vector with a size initially
    *You can also initialize a vector with a size and default values.


    A vector maintains the state of a dynamic array on the heap (which is why we do not need to specify a size when initializing a vector like we do with an array).
    Regardless of the contents of the array, the size of the vector w on the stack will always be constant.
        The vector class has fields such as a pointer to an array on the heap, values to keep track of the size and capacity, etc.
        Therefore, all vectors constructed on the stack will have the same memory footprint on the stack.


*** 

Iterators

    *An iterator is an abstraction for a position in a collection of objects.
	*Container classes in the C++ standard library support iterators.
    *It’s common to think of an iterator as a pointer to an element’s position
    *Though technically it’s not a pointer, but most likely uses a pointer in its implementation.
    *Even though iterators are supported between different types of containers, an iterator can only be used with its own container type.



