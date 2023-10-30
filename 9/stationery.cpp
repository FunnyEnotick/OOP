
#include <stationery.h>

Stationery::Stationery(string pfirm, string pname, int pquantity) {
    this->firm = pfirm;
    this->name = pname;
    this->quantity = pquantity;
}

Stationery::Stationery() {
    this->firm = "";
    this->name = "";
    this->quantity = 0;
}

void Stationery::print() {
    std::cout << "Stationery " <<this->firm << " " << this->name << ": " << this->quantity << endl;
}
