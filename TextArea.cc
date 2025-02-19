#include "TextArea.h"

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include <unistd.h>

using namespace std;

TextArea::TextArea() : 
    id("NoID"), label("Label-less") {
        fill = RGB::WHITE();
        border = RGB::BLACK();
        this->dimensions.height = 30;
        this->dimensions.width = 50;
        this->dimensions.x = 0;
        this->dimensions.y = 0;
    }

TextArea::TextArea(Rectangle dimensions, string id, string label) : 
    id(id), label(label), fill(RGB::WHITE()), border(RGB::BLACK()), dimensions(dimensions){}

TextArea::TextArea(int x, int y, int width, int height, string id, string label) : 
    id(id), label(label), fill(RGB::WHITE()), border(RGB::BLACK()){  
        this->dimensions.height = height;
        this->dimensions.width = width;
        this->dimensions.x = x;
        this->dimensions.y = y;
}

//Copy Constructor
TextArea::TextArea(const TextArea& copyText) 
    : id(copyText.id), text(copyText.text), dimensions(copyText.dimensions), fill(copyText.fill), border(copyText.border){
    cout << "TextArea copied." << endl;
}

//Getters
const string TextArea::getID() { return id;}
const string TextArea::getText() { return text; }
const Rectangle& TextArea:: getDimensions() const { return dimensions; }
const RGB& TextArea::getFill(){ return fill; }
const RGB& TextArea::getBOrder(){ return border; }


//Setters
void TextArea::setFill(const RGB& newFill) { fill = newFill; }
void TextArea::setBorder(const RGB& newBorder) { border = newBorder; }
void TextArea::setDimensions(const Rectangle& newDimension) { dimensions = newDimension; }


void TextArea::draw(Display* display, Window win, GC gc, int x, int y){
    int posX = x + dimensions.x;
    int posY = y + dimensions.y;

    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, posX, posY, dimensions.width, dimensions.height);

    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, posX, posY, dimensions.width, dimensions.height);

    XSetForeground(display, gc, border.getColour());
    XDrawString(display, win, gc, posX + 5, posY + 15, text.c_str(), text.length());

    XFlush(display);
    usleep(20000);
}   

bool TextArea::overlaps(const TextArea& textArea) const{
    return dimensions.overlaps(textArea.getDimensions());
}

void TextArea::print() const{
    cout << "Printing TextArea Information..." << endl;
    cout << "TextArea ID:         " << id << endl;
    cout << "Preferred location:  " << dimensions.x << ", " << dimensions.y << endl;
    cout << "Size:                " << dimensions.width << ", " << dimensions.height << endl;
    cout << "Text:                " << text << endl;
}

