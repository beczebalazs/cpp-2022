//
// Created by Balazs on 11/20/2022.
//

#ifndef MAIN_02_CPP_CEG_H
#define MAIN_02_CPP_CEG_H

#include "Manager.h"

class Ceg {
private:
    vector<Alkalmazott*> alkalmazottak;
public:
    void printManagers() const;
    void printEmployees() const;
    void addEmployee(Alkalmazott* a);
    void addEmpToManager(int empId, int manId);
    void fireEmployee(int id);
    void removeEmpFromManager(int empId, int manId);
    Alkalmazott* findEmpById(int id);
};



#endif //MAIN_02_CPP_CEG_H
