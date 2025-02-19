#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>

#include "defs.h"
#include "RGB.h"

using namespace std;

class TextArea{
    private:
    string id, text, label;
    Rectangle dimensions;
    RGB fill, border;

    public:
    TextArea();
    TextArea(const Rectangle dimensions, const string id, const string label);
    TextArea(int x, int y, int width, int height, const string id, const string label);
    TextArea(const TextArea& copyText);

    const string getID();
    const string getText();
    const Rectangle& getDimensions() const;
    const RGB& getFill();
    const RGB& getBOrder();

    void setText(const string newText);
    void setFill(const RGB& newFill);
    void setBorder(const RGB& newBorder);
    void setDimensions(const Rectangle& newRectangle);
    
    void draw(Display* display, Window win, GC gc, int x, int y);
    bool overlaps(const TextArea& textArea) const;
    void print() const;
};

#endif