//
// Created by Balazs on 10/5/2022.
//

#ifndef MAIN_02_CPP_STACK_H
#define MAIN_02_CPP_STACK_H

#include "List.h"
#include <iostream>
using namespace std;

class Stack{
public:
    Stack();
    ~Stack();
    void push(int e);
    int pop();
    bool isEmpty() const;
    void printStack() const;
private:
    struct StackNode{
        int value;
        StackNode* next;
        StackNode(int v, StackNode *n) : value(v), next(n) {
        }
    };
    StackNode* topPtr;
};


#endif //MAIN_02_CPP_STACK_H
