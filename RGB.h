#ifndef RGB_H
#define RGB_H

#include <iostream>
#include "defs.h"

class RGB{
    private: 
        int r, g, b;

    public:
    RGB(int red, int blue, int green);
    RGB();


    int getR() const;
    int getB() const;
    int getG() const;
    CuColour getColour();

    void setR(int r);
    void setG(int g);
    void setB(int b);
    void setColour(CuColour colour);

    int validateColour(int value);

    const static RGB WHITE();
    const static RGB RED();
    const static RGB BLUE();
    const static RGB GREEN();
    const static RGB BLACK();

    void const print();
    
};

#endif