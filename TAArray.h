#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include <iostream>

class TAArray {
    private:
    TextArea* textAreas[MAX_COMPONENTS];
    int count;

    public: 
    TAArray();
    ~TAArray();

    bool addTextArea(TextArea* ta);
    bool addTextArea(TextArea* ta, int index);

    TextArea* removeTextArea(int index);
    TextArea* removeTextArea(const string& id);

    TextArea* getTextArea(int index) const;
    TextArea* getTextArea(const string& id) const;

    int getCount() const;
    void printTextAreas() const;
};

#endif