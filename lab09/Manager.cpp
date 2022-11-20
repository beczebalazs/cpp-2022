//
// Created by Balazs on 11/16/2022.
//

#include "Manager.h"

const string Manager::MANAGER_MUNKAKOR{"Manager"};

void Manager::print(ostream &os) const {
    os<<"Manager|ID:"<<this->getId()<<" Name: "<<this->getFirstName()<<" "<<this->getLastName()<<" Beosztottjai:"<<endl;

    for (auto a:beosztottak)
    {
        os<<"\t"<<"ID:"<<(*a).getId()<<" Name: "<<(*a).getFirstName()<<" "<<(*a).getLastName()<<" <"<<(*a).getMunkakor()<<">\n";
    }
}

void Manager::addAlkalmazott(Alkalmazott* alk) {
    this->beosztottak.emplace_back(alk);
}

void Manager::deleteAlkalmazott(int id) {

    for (auto it=this->beosztottak.begin();  it!=beosztottak.end();++it)
    {
        if ( (*it)->getId() == id )
        {
            this->beosztottak.erase(it);
            break;
        }
    }
}
