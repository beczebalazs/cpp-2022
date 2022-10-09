//
// Created by Balazs on 10/5/2022.
//

#include "List.h"
#include <iostream>
using namespace std;
List::List() {
    this->first = nullptr;
}

void List::insertFirst(int d) {
    Node* temp = new Node(d,first);
    first = temp;
    ++nodeCounter;;
}

void List::print() const {
    cout<<"[";
    for(Node * ptr = this->first; ptr != nullptr; ptr = ptr->next){
        cout<<ptr->value<< " ";
    }
    cout<<"]"<<endl;
}

List::~List() {
    while (first != nullptr){
        Node* p = first;
        first = first->next;
        delete p;
    }
}

bool List::exists(int d) const {
    Node* temp = first;
    while (temp != nullptr){
        if (temp->value == d){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return first == nullptr;
}

int List::removeFirst() {
    if (empty()){
        cout << "Empty List!\n";
        exit(1);
    }
    int value = first->value;
    Node* temp = first;
    first = first->next;
    delete temp;
    return value;
}