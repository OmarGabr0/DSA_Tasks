#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{


    LinkedList list1;


    list1.add(10);
    cout<<"now the list = ";
    list1.Display();
    cout<<endl;
///////////////////////////////////////////
    cout<<"now the list = ";
    list1.add(30);
    list1.Display();
    cout<<endl;
////////////////////////////////////////////////
    cout<<"now the list = ";
    list1.add(50);
    list1.Display();
    cout<<endl;

///////////////////////////
    list1.add(20);

    cout << "list1= ";
    list1.Display();

/////////////////////////////////////
cout<<endl;
cout<<"====== Test 2 ========"<<endl;


    LinkedList list2;

    list2.add(60);
    cout<<"now the list = ";
    list2.Display();
    cout<<endl;
///////////////////////////////////////////
    cout<<"now the list = ";
    list2.add(30);
    list2.Display();
    cout<<endl;
////////////////////////////////////////////////
    cout<<"now the list = ";
    list2.add(70);
    list2.Display();
    cout<<endl;
////////////////////////////////////////////////
    cout<<"now the list = ";
    list2.add(25);
    list2.Display();
    cout<<endl;

///////////////////////////
    list2.add(20);

    cout << "list1= ";
    list2.Display();

/////////////////////////////////////

cout<<endl<<endl;
    return 0;
}
