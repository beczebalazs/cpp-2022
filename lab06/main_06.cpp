#include <iostream>
#include "Polynomial.h"
int main() {
    Polynomial p1(3,new double[4] {2,5,6,8});
    cout << "P1: " << p1 << endl <<"Degree: " << p1.degree() << endl;
    cout<<"******************************************************************"<<endl;
    Polynomial pcopy(p1);
    cout << "PCopy: " << pcopy << endl << "Degree: " << pcopy.degree() << endl;
    cout<<"******************************************************************"<<endl;
    Polynomial p2(2,new double [3] {1,3,3});
    cout << "P2(=P1): " << p2 << endl <<"Degree: " << p2.degree() << endl;
    cout << "P2(1) = " << p2.evaluate(1) << endl;
    cout<<"******************************************************************"<<endl;
    Polynomial der = p2.derivative();
    cout << "der(P1): " << der << endl <<"DEGREE: " << der.degree() << endl;
    cout << "P1[0] = " << p1[0] << endl;
    cout<<"******************************************************************"<<endl;
    Polynomial p3 = p1 + p2;
    cout << "P3: " << p3 << endl;
    cout << "-P3: " << -p3 << endl;
    cout<<"******************************************************************"<<endl;
    Polynomial p4(1,new double [2]{2,1});
    Polynomial p5(2,new double [3]{1,3,4});
    cout << "p4: " << p4 << endl << "p5: " << p5 << endl;
    cout << "p4+p5 = " << p4-p5 << endl;
    cout << "p4*p5 = " << p4*p5 << endl;
    return 0;
}