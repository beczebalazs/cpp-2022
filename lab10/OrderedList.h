//
// Created by Balazs on 11/25/2022.
//

#ifndef MAIN_02_CPP_ORDEREDLIST_H
#define MAIN_02_CPP_ORDEREDLIST_H

#include <iostream>

using namespace std;

template<class T, class LessComp, class Equal>
class Iterator;

template<class T, class LessComp = less<T>, class Equal = equal_to<T>>
class OrderedList {
private:
    struct Node {
        T value;
        Node* next;
        Node(T value,Node* next=nullptr):value(value),next(next){};
    };
    Node* first {nullptr};
    int numElements = 0;
    friend class Iterator<T,LessComp,Equal>;
public:
    OrderedList(){};
    ~OrderedList(){};
    bool isEmpty(){return first == nullptr;};
    void insert(T value);
    void remove(T value);
    int size();
    bool find(T value);
    void listItems(ostream& os=cout);
};

template<class T, class LessComp, class Equal>
void OrderedList<T,LessComp,Equal>::remove(T value) {
    Node* act = first;
    Node* prev = nullptr;
    while (act != nullptr && act->value != value) {
        prev = act;
        act = act->next;
    }
    if (act == nullptr) {
        cout << "Element not found: " << value << endl;
        return;
    }
    prev->next = act->next;
    delete act;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T value) {
    Node* new_node = new Node(value);
    ++numElements;
    if (first == nullptr) {
        first = new_node;
        return;
    }
    Node* act = first;
    Node* prev = nullptr;
    while (act != nullptr && LessComp()(act->value, value)) {
        prev = act;
        act = act->next;
    }
    if (prev == nullptr) {
        new_node->next = first;
        first = new_node;
        return;
    }
    prev->next = new_node;
    new_node->next = act;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T value) {
    Node* p = first;
    while (p != nullptr) {
        if (p->value == value) {
            return true;
        }
        p = p->next;
    }
    return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &os) {
    Node* p = first;
    while (p != nullptr) {
        os << p->value << " ";
        p = p->next;
    }
    os << endl;
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() {
    return numElements;
}

#endif //MAIN_02_CPP_ORDEREDLIST_H
