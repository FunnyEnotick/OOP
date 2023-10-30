
#include "paper.h"

Paper::Paper(string pfirm, string pname, int pquantity, int psize) : Stationery (pfirm, pname, pquantity) {
    this->size = psize;
}

Paper::Paper() : Stationery () {
    this->size = 0;
}

void Paper::print() {
    std::cout << "Paper " << this->firm << " " << this->name << ": " << this->quantity << " x " << this->size << endl;
}

string Paper::get_firm() {
    return this->firm;
}

int Paper::get_quantity() {
    return this->quantity;
}
