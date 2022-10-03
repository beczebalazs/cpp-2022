//
// Created by Balazs on 10/3/2022.
//

#include "functions.h"

int countBits(int number)
{
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool setBit(int& number, int order)
{
    if (order>31 || order <0)
        return false;
    number= (1<<order) | number;
    return true;
}

double mean(double array[], int numElements)
{
    if (numElements==0)
        return NAN;
    double avg=0;
    for (int i=0;i<numElements;i++)
        avg+=array[i];
    return avg/numElements;
}

double stddev(double array[], int numElements)
{
    if (numElements==0)
        return NAN;
    double sum = 0.0, mean, standardDeviation = 0.0;
    int i;

    for(i = 0; i < 10; ++i) {
        sum += array[i];
    }

    mean = sum / 10;

    for(i = 0; i < 10; ++i) {
        standardDeviation += pow(array[i] - mean, 2);
    }

    return sqrt(standardDeviation / 10);
}

pair<double, double> max2(double array[], int numElements)
{
    if (numElements==0)
        return pair<double, double> (NAN, NAN);
    if (numElements==1)
        return pair<double, double> (array[0], array[0]);

    pair<double, double> res (array[0], array[1]);
    for (int i=0;i<numElements;i++)
    {
        if (array[i]>res.second)
        {
            res.first=res.second;
            res.second=array[i];
        }
        else if (array[i]>res.first)
            res.first=array[i];
    }
    return res;
}

double calcSum(char* argv[], int argc)
{
    double sum=0;
    for (int i=0;i<argc;i++)
    {
        double number;
        istringstream iss(argv[i]);
        if (iss >> number)
            sum+=number;
    }
    return sum;
}

int countWords(string text)
{
    int count=0;
    istringstream iss(text);
    string s;
    while (iss>>s)
        count++;
    return count;
}

string code(string text)
{
    for (int i=0;i<text.length();i++)
    {
        if (text[i]=='z')
            text[i]='a';
        else if (text[i]=='Z')
            text[i]='A';
        else if (isalpha(text[i]))
        {
            text[i]++;
        }
    }
    return text;
}

string capitalizeWords(string text)
{
    text[0]=toupper(text[0]);
    for (int i=1;i<text.length();i++)
    {
        if (text[i-1]==' ' && isalpha(text[i]))
            text[i]= toupper(text[i]);
        else if (isalpha(text[i]))
            text[i]= tolower(text[i]);
    }
    return text;
}

void mostCommonWords(string filename, int n)
{
    int count=0;
    vector<string> words;
    vector<int> instances;
    string s;
    ifstream f(filename);
    while (f>>s)
    {
        bool found=false;
        for (int i = 0; i < count; i++)
            if ( s == words[i]) {
                instances[i]++;
                found=true;
            }

        if (!found) {
            words.push_back(s);
            instances.push_back(1);
            count++;
        }
    }

    for (int i=0;i<n;i++)
    {
        int max=0;
        int maxindex;
        for (int j=0;j<count;j++)
        {
            if (instances[j]>max)
            {
                max=instances[j];
                maxindex=j;
            }
        }
        cout<<words[maxindex]<<": "<<max<<endl;
        instances[maxindex]=0;
    }
    f.close();

}