#ifndef PAPER_H
#define PAPER_H

#include <stationery.h>

class Pen;

class Paper : public Stationery {
public:
    int size;
    Paper(string, string, int, int);
    Paper();
    void print();

    string get_firm();
    int get_quantity();
    friend int get_firm_q(Paper, Pen, string);
};

#endif // PAPER_H
