#ifndef PAPER_H
#define PAPER_H

#include <stationery.h>

using namespace STN;

namespace DRVD {

class Paper : public Stationery {
public:
    int size;
    Paper(string, string, int, int);
    Paper();
    void print();

    string get_firm();
    int get_quantity();

};

}


#endif // PAPER_H
