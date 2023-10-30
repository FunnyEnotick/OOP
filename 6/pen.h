#ifndef PEN_H
#define PEN_H

#include <stationery.h>

class Paper;

class Pen : private Stationery
{
public:
    string type;
    Pen(string, string, int, string);
    Pen();
    void print();

    void set_firm(string);
    void set_name(string);
    void set_quantity(int);

    string get_firm();
    int get_quantity();
    friend int get_firm_q(Paper, Pen, string);
};

#endif // PEN_H
