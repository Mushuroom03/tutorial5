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

    bool add(TextArea* ta);
    bool add(TextArea* ta, int index);

    TextArea* remove(int index);
    TextArea* remove(const string& id);

    TextArea* get(int index) const;
    TextArea* get(const string& id) const;

    int getCount() const;
    void printTextAreas() const;
};

#endif
