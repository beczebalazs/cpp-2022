#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    cout << "Feladat 1:" << endl;
    vector<string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };
    string fruit;
    cout << "Irj egy gyumolcsot:" << endl;
    cin >> fruit;
    auto result1{
            find_if(fruits.begin(), fruits.end(), [fruit](string &string1) {
                return (string1.find(fruit) != string::npos);
            })
    };
    if (result1 != fruits.end()) {
        cout << *result1 << " az elso gyumolcs amiben benne van a keresett gyumolcs: " << fruit << endl;
    } else { cout << "Nincs olyan gyumolcs amiben benne lenne a keresett gyumolcs" << endl; }
    cout << "================================================" << endl;

    cout << "Feladat 2:" << endl;
    cout << "Szamsor: ";
    vector<int> numbers{0, 3, 8, 12, 14, 22};

    for (auto num: numbers) {
        cout << num << " ";
    }
    cout << endl;

    auto result2{
            all_of(numbers.begin(), numbers.end(), [](int &num) {
                return num % 2 == 0;
            })
    };

    if (result2) {
        cout << "Csak paros szamok" << endl;
    } else { cout << "Nem csak paros szamok" << endl; }
    cout << "================================================" << endl;

    cout << "Feladat 3:" << endl;
    cout << "Az elozo szamoknak a duplajai:" << endl;
    for_each(numbers.begin(), numbers.end(), [](int &num) {
        num *= 2;
    });

    for (auto num: numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << "================================================" << endl;

    cout << "Feladat 4:" << endl;
    vector<string> months{
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    cout << "Honapok:" << endl;
    for (auto month: months) {
        cout << month << " ";
    }
    cout << endl;

    int count{0};
    for_each(months.begin(), months.end(), [&count](string &string1) {
        if (string1.size() == 5) count++;
    });

    cout << "5 betus honapok szama: " << count << endl;
    cout << "================================================" << endl;

    cout << "Feladat 5:" << endl;
    cout << "Az elozo szamsorozat csokeno sorrendbe rendezve:" << endl;
    sort(numbers.begin(), numbers.end(), greater<>());
    sort(numbers.begin(), numbers.end(), [](const int &num1, const int &num2) {
        return num1 > num2;
    });

    for (auto num: numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << "================================================" << endl;

    cout << "Feladat 6:" << endl;
    cout << "A honapok az atlag homersekletekkel:" << endl;
    vector<pair<string, double>> monthsTemps{
            {"January",   2},
            {"February",  -3},
            {"March",     8},
            {"April",     15},
            {"May",       19},
            {"June",      24},
            {"July",      30},
            {"August",    41},
            {"September", 28},
            {"October",   26},
            {"November",  16},
            {"December",  -2}
    };

    for (auto month: monthsTemps) {
        cout << month.first << " " << month.second << " ";
    }

    sort(monthsTemps.begin(), monthsTemps.end(),
         [](const pair<string, double> &month1, const pair<string, double> &month2) {
             return month1.second < month2.second;
         });

    cout << "A hoonapok az atlag homerseklet szerinte rendezve:" << endl;
    for (auto month: monthsTemps) {
        cout << month.first << " " << month.second << " ";
    }
    cout << "================================================" << endl;

    cout << "Feladat 7:" << endl;
    cout << "Az elozo szamsorozat rendezve novekvo sorrendbe absolut ertek szerint:" << endl;
    sort(numbers.begin(), numbers.end(), [](const int &num1, const int &num2) {
        return abs(num1) < abs(num2);
    });

    for (auto num: numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << "================================================" << endl;

    cout << "Feladat 8:" << endl;
    cout << "A honapok kicsit kezdobetukkel:" << endl;
    for_each(months.begin(), months.end(), [](auto &month) {
        month[0] = tolower(month[0]);
    });

    for (auto month: months) {
        cout << month << " ";
    }
    cout << endl;
    cout << "================================================" << endl;

    cout << "Feladat 9:" << endl;
    vector<char> abc{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                     't', 'u', 'v', 'w', 'x', 'y', 'z'};

    shuffle(abc.begin(), abc.end(), mt19937(random_device()()));

    cout << "Furcsa abc: ";
    for (auto a: abc) {
        cout << a << " ";
    }
    cout << endl;

    sort(months.begin(), months.end(), [abc](const auto &month1, const auto &month2) {
        return distance(abc.begin(), find(abc.begin(), abc.end(), month1[0])) <
               distance(abc.begin(), find(abc.begin(), abc.end(), month2[0]));
    });

    cout << "A honapok furcsa abc szerint rendezve:" << endl;
    for (auto month: months) {
        cout << month << " ";
    }

    return 0;
}