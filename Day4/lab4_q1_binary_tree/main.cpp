#include <iostream>
#include "Tree.h"

int main()
{
Tree * t = new Tree();
Employee e1(1,23,"omar"),e2(2,24,"omar bardo"),e3(5,25,"omar omar"),e4(4,21,"akeed omar");
t->Insert(e1);
t->Insert(e2);
t->Insert(e3);
t->Insert(e4);
/// test get max
cout<<"================== Max test ================"<<endl;
Node * maxptr = t->GetMaximum();
cout<<"Maxmum employee has ID ="<<maxptr->emp.id<<endl<<"Name: "<<maxptr->emp.name<<endl<<"age:"<<maxptr->emp.age<<endl;

/// test get minmum
cout<<"================ Min test =================="<<endl;
Node * minptr=t->GetMinmum();
cout<<"Minmum employee has ID ="<<minptr->emp.id<<endl<<"Name: "<<minptr->emp.name<<endl<<"age:"<<minptr->emp.age<<endl<<endl;
cout<<"================ DFS test =================="<<endl;

t->DFS();

return 0;
}
