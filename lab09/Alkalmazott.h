//
// Created by Balazs on 11/16/2022.
//

#ifndef MAIN_02_CPP_ALKALMAZOTT_H
#define MAIN_02_CPP_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott:public Szemely {
protected:
    static int Alk_id;
    string munkakor;
    int id;
public:
    string getMunkakor() const {return this->munkakor;}
    Alkalmazott(const string &keresztnev, const string &vezeteknev, int szulEv, const string &munkakor);
    virtual void print(ostream& os=cout) const;
    int getId() const {return this->id;}
};



#endif //MAIN_02_CPP_ALKALMAZOTT_H
