#include <iostream>
#include "RGB.h"
#include "defs.h"

using namespace std;

RGB::RGB(int red, int green, int blue) : r(validateColour(red)), g(validateColour(green)), b(validateColour(blue)) {}
RGB::RGB() : r(0), g(0), b(0) {}

//Getters
int RGB::getR() const{
    return r;
}

int RGB::getB() const{
    return b;
}

int RGB::getG() const{
    return g;
}

CuColour RGB::getColour(){
    return (r << 16) | (g << 8) | b;
}


//Setters
void RGB::setR(int red){
    r = validateColour(red);
}

void RGB::setB(int blue){
    b = validateColour(blue);
}

void RGB::setG(int green){
    g = validateColour(green);
}

void RGB::setColour(CuColour colour){
    r = validateColour((colour >> 16) & 0xFF);
    g = validateColour((colour >> 8) & 0xFF);
    b = validateColour(colour & 0xFF);
}


//Check to ensure the colour is valid and if not, then adjust it so that it is to either value 0 or 255
int RGB::validateColour(int value){
    if(value < 0 || value > 255){
        //sets value to 0 if its less than 0
        if(value < 0)
            return 0;
        //sets value to 255 if greater than 255
        else 
            return 255;
    }
    return value;
}


//Static functions
const RGB RGB::WHITE(){
    return RGB(255, 255, 255);
}

const RGB RGB:: RED(){
    return RGB(255, 0, 0);
}

const RGB RGB:: GREEN(){
    return RGB(0, 255, 0);
}

const RGB RGB:: BLUE(){
    return RGB(0, 0, 255);
}

const RGB RGB:: BLACK(){
    return RGB(0, 0, 0);
}

void const RGB::print(){
    cout << "Printing Object Colour Values..." << endl;
    cout << "R: " << r << endl;
    cout << "G: " << g << endl;
    cout << "B: " << b << endl;
}
