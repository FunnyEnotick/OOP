
#include <stationery.h>
#include <paper.h>
#include <pen.h>
#include <linkedlist.h>

int main()
{
    int COUNT = 10000;

    string firms[] = {"AOL", "Erich", "Stapler", "Grande", "Venti"};
    string names[] = {"Eve", "Stallion", "Honor", "Midt", "Otter"};

    LinkedList<Pen> * List = new LinkedList<Pen>();



    for (int i = 0; i < COUNT; ++i) {
        int alpha = rand() % 5;
        int beta = rand() % 5;
        int gamma = rand() % 10;
        Pen obj = Pen(firms[alpha], names[beta], gamma);
        List->insert(obj);
    }

    //List->print();

    string to_find;
    cout << endl << "Enter firm name:" << endl;
    cin >> to_find;

    int sum = List->count(to_find);
    cout << to_find << ": " << sum << endl;

    delete List;

    return 0;
}
