#include <iostream>
#include <string>
#include "Zipper.h"

Zipper::Zipper(int height, int width): myHeight(height), myWidth(width){
    
}

int Zipper::getHeight() const{
    return myHeight;
}

int Zipper::getWidth() const{
    return myWidth;
}