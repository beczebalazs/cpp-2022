//
// Created by Balazs on 11/16/2022.
//

#include "Alkalmazott.h"

int Alkalmazott::Alk_id{0};

Alkalmazott::Alkalmazott(const string &keresztnev, const string &vezeteknev, int szulEv, const string &munkakor)
        : Szemely(keresztnev, vezeteknev, szulEv) {
    this->id=++Alk_id;
    this->munkakor=munkakor;
}

void Alkalmazott::print(ostream &os) const{
    Szemely::print(os);
    os<<"Munkakor: "<< this->getMunkakor()<<" Id:"<<this->getId()<<endl;
}
