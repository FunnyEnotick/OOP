
#include "pen.h"

string Pen::type = "Ball";

Pen::Pen(string pfirm, string pname, int pquantity, string ptype) : Stationery (pfirm, pname, pquantity) {
    this->set_type(ptype);
}

Pen::Pen(string pfirm, string pname, int pquantity) : Stationery (pfirm, pname, pquantity) {

}

Pen::Pen() : Stationery () {
    this->type = "";
}

Pen::Pen(const Pen &ptr) {
    this->firm = ptr.firm;
    this->name = ptr.name;
    this->quantity = ptr.quantity;
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

string Pen::get_type() {
    return type;
}

void Pen::set_type(string ptype) {
    type = ptype;
}
