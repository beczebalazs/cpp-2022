//
// Created by Balazs on 11/16/2022.
//

#ifndef MAIN_02_CPP_MANAGER_H
#define MAIN_02_CPP_MANAGER_H


#include "Alkalmazott.h"
#include <vector>

class Manager:public Alkalmazott {
    static const string MANAGER_MUNKAKOR;
private:
    vector<Alkalmazott*> beosztottak;
public:
    Manager(const string &keresztnev, const string &vezeteknev, int szulEv, const string &munkakor):Alkalmazott(keresztnev, vezeteknev, szulEv, MANAGER_MUNKAKOR){};
    virtual void print(ostream& os=cout) const;
    void addAlkalmazott(Alkalmazott* alk);
    int beosztottakSzama() {return beosztottak.size();}
    void deleteAlkalmazott(int id);
};


#endif //MAIN_02_CPP_MANAGER_H
