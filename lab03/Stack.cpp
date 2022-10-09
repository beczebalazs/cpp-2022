//
// Created by Balazs on 10/5/2022.
//

#include "Stack.h"

Stack::Stack() {
    cout << " CONSTRUCTOR ";
    topPtr = nullptr;
}

Stack::~Stack() {
    cout << " DESTRUCTOR ";
    while (topPtr != nullptr){
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

bool Stack::isEmpty() const {
    return topPtr == nullptr;
}

void Stack::push(int e) {
    auto* temp = new StackNode(e,topPtr);
    temp->next = topPtr;
    topPtr = temp;
}

int Stack::pop() {
    if (isEmpty()){
        cout << "Empty Stack!\n";
        exit(2);
    }
    int value = topPtr->value;
    StackNode* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
    return value;
}

void Stack::printStack() const {
    StackNode* temp = topPtr;
    while (temp != nullptr){
        cout << temp->value << " ";
        temp = temp->next;
    }
}