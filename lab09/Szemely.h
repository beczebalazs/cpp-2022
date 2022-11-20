//
// Created by Balazs on 11/16/2022.
//

#ifndef MAIN_02_CPP_SZEMELY_H
#define MAIN_02_CPP_SZEMELY_H


#include <string>
#include <iostream>

using namespace std;

class Szemely {
protected:
    string vezeteknev;
    string keresztnev;
    int szuletesiEv;
public:
    virtual void print(ostream& os = cout) const;
    Szemely(const string& keresztnev, const string& vezeteknev, int szulEv);
    string getFirstName() const {return this->keresztnev;}
    string getLastName() const {return this->vezeteknev;}

};
ostream& operator<<(ostream& os, const Szemely& sz);

#endif //MAIN_02_CPP_SZEMELY_H
