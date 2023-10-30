
#include "stationery.h"
#include <paper.h>
#include <pen.h>
#include <vector>

using std::vector;

/*PRINT FUNC*/
void print(vector<Pen> v) {
    cout << endl;
    for (Pen it : v) {
        it.print();
    }
}

/*FUNC TO COUNT FIRMS*/
int countF(string s, vector<Pen> v) {
    int sum = 0;
    Stationery St = Stationery(s, "blank", 0);

    for (Pen it : v) {
        if(it==St)
            sum+=it.get_quantity();
    }

    return sum;
}

int main()
{
    const int COUNT = 500;
    string firms[] = {"AOL", "Erich", "Stapler", "Grande", "Venti"};
    string names[] = {"Eve", "Stallion", "Honor", "Midt", "Otter"};

    vector<Pen> data;

    for(int i = 0; i < COUNT; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        data.push_back(Pen(firms[alpha], names[beta], gamma));
    }
    print(data);

    string to_find = firms[rand() % 5];
    int sum = countF(to_find, data);

    cout << to_find << ": " << sum << endl;

    int length = data.size()/2;

    vector<Pen> ins;
    for(int i = 0; i < 200; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        ins.push_back(Pen(firms[alpha], names[beta], gamma));
    }
    for (Pen it: ins) {
        data.insert(data.cbegin()+length, it);
    }
    print(data);

    sum = countF(to_find, data);
    cout << to_find << ": " << sum << endl;

    vector<Pen> reverse;
    for (Pen it: data) {
        reverse.insert(reverse.cbegin(), it);
    }
    //print(reverse);

    data.clear(); ins.clear(); reverse.clear();
    cout << "DATA SIZE: " << data.size() << "; INS SIZE: " << ins.size() << "; REVERSE SIZE: " << reverse.size() << endl;

    return 0;

    vector<Pen> ins2;
    print(ins2);
    int alpha = rand() % 5;
    int beta = rand() % 5;
    int gamma = rand() % 10;
    ins.push_back(Pen(firms[alpha], names[beta], gamma));
    print(ins2);
}
