
#include <stationery.h>
#include <paper.h>
#include <pen.h>

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
        pr_ptr[i] = Paper(firms[alpha], names[beta], gamma);
    }

    for (int i = 0; i < PEN_Q; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        pn_ptr[i] = Pen(firms[alpha], names[beta], gamma);
    }

    cout << "Enter firm name to find:" << endl;
    string to_find;
    int sum = 0;

    cin >> to_find;

    Stationery St = Stationery(to_find, "blank", 0);

    for (int i = 0; i < PAPER_Q; ++i) {
        if(pr_ptr[i]==St)
            sum+=pr_ptr[i].get_quantity();
    }
    for (int i = 0; i < PEN_Q; ++i) {
        if(pn_ptr[i]==St)
            sum+=pn_ptr[i].get_quantity();
    }

    cout << to_find << ": " << sum << endl;

    delete[] pr_ptr, pn_ptr;

    return 0;
}
