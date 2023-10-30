#ifndef PEN_H
#define PEN_H

#include <stationery.h>

using namespace STN;

namespace DRVD {

class Pen : public Stationery
{
public:
    string type;
    Pen(string, string, int, string);
    Pen();
    void print();

    string get_firm();
    int get_quantity();

};

}



#endif // PEN_H
