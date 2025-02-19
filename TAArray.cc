#include "TAArray.h"


TAArray::TAArray() : count(0) {
    for(int i = 0; i < MAX_COMPONENTS; i++)
        textAreas[i] = nullptr;
}

TAArray::~TAArray(){
    for(int i = 0; i < count; i++)
        delete textAreas[i];
}

bool TAArray::addTextArea(TextArea* ta){
    if (count >= MAX_COMPONENTS) {
        cout << "Array is full." << endl;
        return false;
    }
    textAreas[count++] = ta;
    return true;
}

bool TAArray::addTextArea(TextArea* ta, int index){
    if(index <0 || index >= count || count >= MAX_COMPONENTS){
        cout << "Invalid index or TAArray is full." << endl;
        return false;
    }
    for(int i = count; i < index; i--){
        textAreas[i] = textAreas[i-1];
    }
    textAreas[index] = ta;
    count++;
    return true;
}

TextArea* TAArray::removeTextArea(int index){
    if(index < 0 || index >= count){
        cout << "Invalid index" << endl;
        return nullptr;
    }
    TextArea* removedTA = textAreas[index];

    for(int i = index; i < count - 1; i++){
        textAreas[i] = textAreas[i + 1];
    }
    textAreas[count-1] = nullptr;
    count--;
    return removedTA;
}

TextArea* TAArray::removeTextArea(const string& id){
    for (int i = 0; i < count; i++) {
        if (textAreas[i]->getID() == id) {  // Compare IDs
            return removeTextArea(i);  // Remove by index
        }
    }
    return nullptr;
}

TextArea* TAArray::getTextArea(int index) const {
    if (index < 0 || index >= count) {
        std::cerr << "Invalid index!" << std::endl;
        return nullptr;
    }
    return textAreas[index];
}

TextArea* TAArray::getTextArea(const std::string& id) const {
    for (int i = 0; i < count; i++) {
        if (textAreas[i]->getID() == id) {
            return textAreas[i];
        }
    }
    return nullptr;
}

int TAArray::getCount() const {
    return count;
}

void TAArray::printTextAreas() const {
    std::cout << "TAArray contains " << count << " TextAreas:\n";
    for (int i = 0; i < count; i++) {
        textAreas[i]->print();
    }
} 