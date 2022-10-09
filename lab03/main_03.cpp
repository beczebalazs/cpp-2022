#include <iostream>
#include "List.h"
#include "Stack.h"

using namespace std;

int main() {
    cout << "1. List" << endl;
    cout << "2. Stack" << endl;
    cout << "Option:";
    int option;
    cin >> option;
    switch (option) {
        case 1: {
            List *list = new List();
            list->insertFirst(4);
            list->insertFirst(6);
            list->insertFirst(7);
            list->insertFirst(8);
            list->print();
            cout << "\nSize of list: " << list->size() << endl;
            cout << "4 found in list?: " << list->exists(4);
//    int first = list->removeFirst();
//    cout << first << endl;
//    if (list->empty()){
//        cout << "Empty!\n";
//    }
            break;
        }
        case 2:{
            auto* stack = new Stack();
            stack->push(10);
            stack->push(20);
            stack->push(50);
            stack->push(30);
            stack->push(40);
            cout << "\nPopped value:" << stack->pop() << endl;
            stack->printStack();
            break;
        }
        default:{
            cout << "No such option!" << endl;
            break;
        }
    }
    return 0;
}
