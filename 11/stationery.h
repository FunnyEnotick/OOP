
#ifndef STATIONERY_H
#define STATIONERY_H


#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Stationery
{
public:
    string firm;
    string name;
    int quantity;

    Stationery(string, string, int);
    Stationery();
    virtual void print();

    bool operator==(const Stationery R) {
        return this->firm==R.firm;
    }
};

#endif // STATIONERY_H
