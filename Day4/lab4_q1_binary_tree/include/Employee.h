#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <cstring>

class Employee
{
    public:
        int id ;
        int age;
        char name [20];
        Employee(int _id,int _age,char _name[20]){
            id=_id;
            age=_age;
             strcpy(name, _name);
        }

    private:
};

#endif // EMPLOYEE_H
