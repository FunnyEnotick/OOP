
#include <stationery.h>
#include <paper.h>
#include <pen.h>

using namespace STN;
using namespace DRVD;

int get_firm_q(Paper * paper, string str) {
    int sum = 0;
    if (paper->get_firm()==str) sum += paper->get_quantity();
    return sum;
}

int get_firm_q(Pen * pen, string str) {
    int sum = 0;
    if (pen->get_firm()==str) sum += pen->get_quantity();
    return sum;
}

int main()
{
    const int PAPER_Q = 100;
    const int PEN_Q = 100;

    Paper * pr_ptr = new Paper[PAPER_Q];
    Pen * pn_ptr = new Pen[PEN_Q];

    string firms[] = {"AOL", "Erich", "Stapler", "Grande", "Venti"};
    string names[] = {"Eve", "Stallion", "Honor", "Midt", "Otter"};

    for (int i = 0; i < PAPER_Q; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        pr_ptr[i] = Paper(firms[alpha], names[beta], gamma, 150);
    }

    for (int i = 0; i < PEN_Q; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        pn_ptr[i] = Pen(firms[alpha], names[beta], gamma, "AUTO");
    }

    cout << "Enter firm name to count." << endl;
    string to_find;
    cin >> to_find;

    int sum = 0; 

    for (int i = 0; i < PAPER_Q; ++i) {
        sum += get_firm_q(&pr_ptr[i], to_find);
    }
    for (int i = 0; i < PEN_Q; ++i) {
        sum += get_firm_q(&pn_ptr[i], to_find);
    }

    cout << to_find << ": " << sum << endl;

    delete[] pr_ptr, pn_ptr;

    return 0;
}
