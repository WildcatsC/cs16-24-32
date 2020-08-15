#ifndef ZIPPER_H
#define ZIPPER_H

class Zipper{
    private: 
    int myHeight;
    int myWidth;

    public: 
    Zipper(int height, int width);
    int getHeight() const;
    int getWidth() const;
};

#endif // !ZIPPER_H
