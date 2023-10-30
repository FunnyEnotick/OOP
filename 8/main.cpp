
#include <stationery.h>
#include <paper.h>
#include <pen.h>

int get_firm_q(Paper * ptr, string str) {
    int sum = 0;
    if (ptr->get_firm()==str) sum += ptr->get_quantity();
    return sum;
}

int get_firm_q(Pen * ptr, string str) {
    int sum = 0;
    if (ptr->get_firm()==str) sum += ptr->get_quantity();
    return sum;
}

int get_firm_Arr(Paper * ptr, int cnt, string str) {
    int sum = 0;
    for (int i = 0; i < cnt; ++i) {
        sum += get_firm_q(&ptr[i],str);
    }
    return sum;
}

int get_firm_Arr(Pen * ptr, int cnt, string str) {
    int sum = 0;
    for (int i = 0; i < cnt; ++i) {
        sum += get_firm_q(&ptr[i],str);
    }
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
        pr_ptr[i] = Paper(firms[alpha], names[beta], gamma, 200);
    }

    for (int i = 0; i < PEN_Q; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        pn_ptr[i] = Pen(firms[alpha], names[beta], gamma, "BALL");
    }

    cout << "Enter firm name to find:" << endl;
    string to_find;
    int sum = 0;

    cin >> to_find;

    sum += get_firm_Arr(pr_ptr, PAPER_Q, to_find);
    sum += get_firm_Arr(pn_ptr, PEN_Q, to_find);

    cout << to_find << ": " << sum << endl;

    delete[] pr_ptr, pn_ptr;

    return 0;
}
