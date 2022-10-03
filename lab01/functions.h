//
// Created by Balazs on 10/3/2022.
//

#ifndef MAIN_02_CPP_FUNCTIONS_H
#define MAIN_02_CPP_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <math.h>
#include <utility>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int countBits(int);
bool setBit(int&, int);
double mean(double[], int);
double stddev(double[], int);
pair<double, double> max2(double[], int);
int countWords(string);
string code(string);
double calcSum(char* [], int);
string capitalizeWords(string);
void mostCommonWords(string, int);

template <typename T>
void print_container(const T array[] , int numOfElements)
{
    for (int i=0;i<numOfElements;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
#endif //MAIN_02_CPP_FUNCTIONS_H
