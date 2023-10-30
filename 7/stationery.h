#ifndef STATIONERY_H
#define STATIONERY_H

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

namespace STN {

class Stationery
{
public:
    string firm;
    string name;
    int quantity;

    Stationery(string, string, int);
    Stationery();
    virtual void print();

};

}

#endif // STATIONERY_H
