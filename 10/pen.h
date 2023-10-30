#ifndef PEN_H
#define PEN_H

#include <stationery.h>

class Pen : public Stationery
{
public:
    static string type;
    Pen(string, string, int, string);
    Pen(string, string, int);
    Pen();
    void print();

    string get_firm();
    int get_quantity();
    string get_type();
    void set_type(string);
    Pen(const Pen &);

    bool operator==(const Stationery R) {
        return this->firm==R.firm;
    }
};

#endif // PEN_H
