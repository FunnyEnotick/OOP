
#include "paper.h"

int Paper::size = 200;

Paper::Paper(string pfirm, string pname, int pquantity, int psize) : Stationery (pfirm, pname, pquantity) {
    this->set_size(psize);
}

Paper::Paper(string pfirm, string pname, int pquantity) : Stationery (pfirm, pname, pquantity) {

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

int Paper::get_size() {
    return size;
}

void Paper::set_size(int psize) {
    size = psize;
}
