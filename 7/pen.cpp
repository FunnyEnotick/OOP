
#include "pen.h"

using namespace STN;
using namespace DRVD;

Pen::Pen(string pfirm, string pname, int pquantity, string ptype) : Stationery (pfirm, pname, pquantity) {
    this->type = ptype;
}

Pen::Pen() : Stationery () {
    this->type = "";
}

void Pen::print() {
    std::cout << "Pen " <<this->firm << " " << this->name << ": " << this->quantity << " " << this->type << endl;
}

string Pen::get_firm() {
    return this->firm;
}

int Pen::get_quantity() {
    return this->quantity;
}
