
#include "pen.h"

Pen::Pen(string pfirm, string pname, int pquantity, string ptype) : Stationery (pfirm, pname, pquantity) {
    this->type = ptype;
}

Pen::Pen() : Stationery () {
    this->type = "";
}

void Pen::print() {
    std::cout << "Pen " <<this->firm << " " << this->name << ": " << this->quantity << " " << this->type << endl;
}

void Pen::set_firm(string frm) {
    this->firm = frm;
}

void Pen::set_name(string nme) {
    this->name = nme;
}

void Pen::set_quantity(int qnt) {
    this->quantity = qnt;
}

string Pen::get_firm() {
    return this->firm;
}

int Pen::get_quantity() {
    return this->quantity;
}
