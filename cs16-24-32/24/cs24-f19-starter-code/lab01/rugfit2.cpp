// rugfit2.cpp - calculates fit of rug to a floor
// YOUR NAME(S), TODAY'S DATE

#include <iostream>
using namespace std;

// definition of class Rectangle
// (usually would be in a separate file named rectangle.h)
class Rectangle {

public:
    // DECLARE a parameterized constructor to set the width and length
     
    // DECLARE accessors to get the width and length

    // DECLARE mutators to set the width and lengtg

    // DECLARE (const) METHOD TO RETURN AREA OF RECTANGLE
    

private:
    double width, length;

}; // end of class definition

// implementation of class Rectangle here to main function
// (usually would be in a separate file named rectangle.cpp,
// and this separate file would #include "rectangle.h")

// IMPLEMENT CONSTRUCTOR USING INITIALIZATION LIST


// IMPLEMENT ACCESSORS and MUTATORS


// IMPLEMENT THE AREA METHOD HERE




// change main where instructed in UPPER CASE below
// (usually would #include "rectangle.h" before main)
int main() {
    
    double width, length;
    Rectangle rug(0,0); // will be updated below

    // create Rectangle named "floor" for sizes input by user
    cout << "enter width and length of floor: ";
    cin >> width >> length;
    const Rectangle floor(width, length); // note: const object

    // RESET Rectangle NAMED "rug" FOR SIZES INPUT BY USER
    
    
    
    // DO NOT CHANGE ANYTHING BELOW (if you do, you will earn 0 points,
    // no matter what submit.cs says is your "tentative" score)

    // print results
    cout << "floor area: " << floor.area() << endl;
    cout << "rug area: " << rug.area() << endl;
    double leftover = rug.area() - floor.area();
    cout << "leftover rug area: " <<
        (leftover > 0 ? leftover : 0) << endl;
    cout << "empty floor area: " <<
        (leftover < 0 ? -leftover : 0) << endl;

    return 0;
}
