#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list1;


    list1.add(10);
    list1.add(20);
    list1.add(30);
    list1.add(40);

    cout << "list1: ";
    list1.Display();
    cout << endl;


    list1.insertAfter(20, 25);
    cout << " insertAfter(20,25): ";
    list1.Display();
    cout << endl;


    list1.insertBefore(30, 28);
    cout << " insertBefore(30,28): ";
    list1.Display();
    cout << endl;


    cout << "Search 25: " << (list1.Search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (list1.Search(100) ? "Found" : "Not Found") << endl;
    cout << endl;


    cout << "Number of nodes: " << list1.count() << endl;
    cout << endl;


    cout << "Data at index 3: " << list1.getDataByIndex(3) << endl;
    cout << endl;


    list1.reverse();
    cout << "In-place reverse: ";
    list1.Display();
    cout << endl;


    LinkedList revList = list1.reversenew();
    cout << "New reversed copy: ";
    revList.Display();
    cout << endl;


    list1.removekth(2);
    cout << "After removekth(2): ";
    list1.Display();
    cout << endl;


    LinkedList list2;
    list2.add(10);
    list2.add(28);
    list2.add(20);
    cout << "list2: ";
    list2.Display();
     cout << endl;
    cout << "list1: ";
    list1.Display();
    cout << endl;

    LinkedList inter = list1.intersection(list2);
    cout << "Intersection of list1 and list2: ";
    inter.Display();
    cout << endl;

    return 0;
}
