#ifndef PAPER_H
#define PAPER_H

#include <stationery.h>

class Paper : public Stationery {
public:
    static int size;
    Paper(string, string, int, int);
    Paper(string, string, int);
    Paper();
    void print();

    string get_firm();
    int get_quantity();
    int get_size();
    void set_size(int);

    bool operator==(const Stationery R) {
        return this->firm==R.firm;
    }

};

#endif // PAPER_H
