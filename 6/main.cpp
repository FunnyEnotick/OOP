
#include <stationery.h>
#include <paper.h>
#include <pen.h>

int get_firm_q(Paper paper, Pen pen, string str) {
    int sum = 0;
    if (paper.get_firm()==str) sum += paper.get_quantity();
    if (pen.get_firm()==str) sum += pen.get_quantity();
    return sum;
}


int main()
{


    const int COUNT = 10;

    Paper * pr_ptr = new Paper[COUNT];
    Pen * pn_ptr = new Pen[COUNT];

    string firms[] = {"AOL", "Erich", "Stapler", "Grande", "Venti"};
    string names[] = {"Eve", "Stallion", "Honor", "Midt", "Otter"};

    for (int i = 0; i < COUNT; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        pr_ptr[i] = Paper(firms[alpha], names[beta], gamma, 150);
        pr_ptr[i].print();
    }

    for (int i = 0; i < COUNT; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        pn_ptr[i] = Pen(firms[alpha], names[beta], gamma, "BALL");
        pn_ptr[i].print();
    }

    cout << "Enter firm name to find." << endl;
    string to_find;
    int sum = 0;

    cin >> to_find;

    for (int i = 0; i < COUNT; ++i) {
        sum += get_firm_q(pr_ptr[i], pn_ptr[i], to_find);
    }

    cout << to_find << ": " << sum << endl;

    delete[] pr_ptr, pn_ptr;

    return 0;
}
