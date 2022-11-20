#include "Ceg.h"

int main() {
    Alkalmazott a1("Balint", "Zsolt", 2001, "Elado");
    Alkalmazott a2("Ferencz", "Szilard", 2002, "Elado");
    Alkalmazott a3("Laczko", "Peter", 2003, "Elado");
    Alkalmazott a4("Sakter", "Elod", 2004, "Elado");
    Alkalmazott a5("Antal", "Balazs", 2005, "Elado");
    Alkalmazott a6("Gal", "Atto", 2006, "Elado");
    Alkalmazott a7("Szabo", "Balazs", 2007, "Elado");
    Manager m1("Becze", "Balazs", 1991, "Fonok");
    Manager m2("Becze", "Attila", 1992, "Fonok");
    Manager m3("Boros", "Boti", 1993, "Fonok");

    Ceg c1;
    c1.addEmployee(&a1);
    c1.addEmployee(&a2);
    c1.addEmployee(&a3);
    c1.addEmployee(&a4);
    c1.addEmployee(&a5);
    c1.addEmployee(&a6);
    c1.addEmployee(&a7);
    c1.addEmployee(&m1);
    c1.addEmployee(&m2);
    c1.addEmployee(&m3);
    c1.printEmployees();
    c1.addEmpToManager(1, 8);
    c1.addEmpToManager(2, 8);
    c1.addEmpToManager(3, 9);
    c1.addEmpToManager(4, 10);
    c1.addEmpToManager(5, 10);
    c1.addEmpToManager(6, 9);
    c1.addEmpToManager(7, 8);
    cout<<"\nMANAGERS:"<<endl;
    c1.printManagers();
    c1.removeEmpFromManager(1, 8);
    c1.addEmpToManager(1, 9);
    cout<<"\n 1-es Alkalmazott athelyezve a 9-es mendezserhez!\n";
    c1.printManagers();
    return 0;
}