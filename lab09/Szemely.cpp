//
// Created by Balazs on 11/16/2022.
//

#include "Szemely.h"

void Szemely::print(ostream &os) const {
    os<<"Nev: "<<this->vezeteknev<<" "<<this->keresztnev<<" Szul. ev:"<<this->szuletesiEv<<endl;
}

Szemely::Szemely(const string &keresztnev, const string &vezeteknev, int szulEv) {
    this->szuletesiEv=szulEv;
    this->keresztnev=keresztnev;
    this->vezeteknev=vezeteknev;
}

ostream &operator<<(ostream &os, const Szemely &sz) {
    sz.print(os);
    return os;
}
