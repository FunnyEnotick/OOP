
#include "pen.h"

Pen::Pen(string pfirm, string pname, int pquantity, string ptype) : Stationery (pfirm, pname, pquantity) {
    this->type = new string;
    * this->type = ptype;
}

Pen::Pen(const Pen &ptr) {
    this->firm = ptr.firm;
    this->name = ptr.name;
    this->quantity = ptr.quantity;
    this->type = new string;
    * this->type = * ptr.type;
}

Pen::Pen() : Stationery () {
    this->type = new string;
    * this->type = "";
}

Pen::~Pen() {
    delete this->type;
}

void Pen::print() {
    std::cout << "Pen " <<this->firm << " " << this->name << ": " << this->quantity << " " << * this->type << endl;
}

string Pen::get_firm() {
    return this->firm;
}

int Pen::get_quantity() {
    return this->quantity;
}
