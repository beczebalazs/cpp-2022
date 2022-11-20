//
// Created by Balazs on 11/20/2022.
//

#include "Ceg.h"

void Ceg::addEmployee(Alkalmazott* a) {
    alkalmazottak.emplace_back(a);
}

void Ceg::printEmployees() const {
    for ( auto a: alkalmazottak)
    {
        (*a).print();
    }
}

void Ceg::fireEmployee(int id) {
    for (auto it=this->alkalmazottak.begin();  it!=alkalmazottak.end();++it)
    {
        if ( (*it)->getId() == id )
        {
            this->alkalmazottak.erase(it);
            break;
        }
    }
}

void Ceg::printManagers() const {
    for (auto a: alkalmazottak)
    {
        if ((*a).getMunkakor()=="Manager")
        {
            (*a).print();
        }
    }
}

void Ceg::addEmpToManager(int empId, int manId) {
    for (auto a: alkalmazottak)
    {
        if ((*a).getMunkakor()=="Manager" && (*a).getId()==manId)
        {
            auto * c = dynamic_cast<Manager*>(a);
            if (c)
                c->addAlkalmazott(findEmpById(empId));
            break;
        }
    }
}

void Ceg::removeEmpFromManager(int empId, int manId) {
    for (auto a: alkalmazottak)
    {
        if ((*a).getMunkakor()=="Manager" && (*a).getId()==manId)
        {
            auto * c = dynamic_cast<Manager*>(a);
            if (c)
                c->deleteAlkalmazott(empId);
            break;
        }
    }
}

Alkalmazott* Ceg::findEmpById(int id) {
    for (auto it : alkalmazottak)
    {
        if ((*it).getId()==id)
        {
            return it;
        }
    }
    return nullptr;
}
