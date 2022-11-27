//
// Created by Balazs on 11/25/2022.
//

#ifndef MAIN_02_CPP_ITERATOR_H
#define MAIN_02_CPP_ITERATOR_H


#include <iostream>
#include "OrderedList.h"

using namespace std;

template<class T, class LessComp = less<T>, class Equal = equal_to<T>>
class Iterator {
private:
    OrderedList<T,LessComp,Equal>& list;
    typename OrderedList<T,LessComp,Equal>::Node* act = list.first;
public:
    Iterator(OrderedList<T,LessComp,Equal>& list):list(list){};
    bool hasNext(){return act->next != nullptr;};
    T next(){act=act->next;return act->value;};
};

#endif //MAIN_02_CPP_ITERATOR_H
