#include <iostream>
#include "Queue_linked.h"
#include "Stack.h"
#include "queue_circ.h"
using namespace std;

int main()
{
    cout << "===================================" << endl;
    cout << "             Stack Test" << endl;
    cout << "===================================" << endl;

    Stack stk1(5);

    for(int i = 1; i < 10; i++)
    {
        if(!stk1.push(i * 10))
            break;

        cout << "Pushing " << i*10 << " into the stack" << endl;
    }

    int val;

    for(int i = 0; i < 12; i++)
    {
        if(!stk1.pop(val))
            break;

        cout << "=========== testing stk pop ============" << endl;
        cout << val << endl;
    }


    cout << endl << endl;
    cout << "===================================" << endl;
    cout << "       Queue using linked list test" << endl;
    cout << "===================================" << endl << endl;

    Queue_linked ql(5);

    for(int i = 1; i < 10; i++)
    {
        if(!ql.enqueue(i * 10))
            break;

        cout << "enqueue q(" << i-1 << ") = " << i*10 << endl;
    }

    for(int i = 0; i < 10; i++)
    {
        if(!ql.dequeue(val))
            break;

        cout << "=========== testing queue dequeue ============" << endl;
        cout << "dequeue = " << val << endl;
    }


    cout << endl << endl;
    cout << "===================================" << endl;
    cout << "       Circular Queue (Array) Test" << endl;
    cout << "===================================" << endl << endl;

    queue_circ q(5);

    cout << "Enqueue 10: " << (q.enqueue(10) ? "OK" : "Fail") << endl;
    cout << "Enqueue 20: " << (q.enqueue(20) ? "OK" : "Fail") << endl;
    cout << "Enqueue 30: " << (q.enqueue(30) ? "OK" : "Fail") << endl;
    cout << "Enqueue 40: " << (q.enqueue(40) ? "OK" : "Fail") << endl;
    cout << "Enqueue 50: " << (q.enqueue(50) ? "OK" : "Fail") << endl;
    cout << "Enqueue 60 (should fail): " << (q.enqueue(60) ? "OK" : "Fail") << endl;

    cout << endl;

    int x;

    cout << "Dequeue: "  << (q.dequeue(x) ? "OK, got = " + to_string(x) : "Fail") << endl;
    cout << "Dequeue: "  << (q.dequeue(x) ? "OK, got = " + to_string(x) : "Fail") << endl;

    cout << endl;

    cout << "Enqueue 100: " << (q.enqueue(100) ? "OK" : "Fail") << endl;
    cout << "Enqueue 200: " << (q.enqueue(200) ? "OK" : "Fail") << endl;

    cout << endl;

    cout << "Now emptying queue..." << endl;
    while(q.dequeue(x))
    {
        cout << "Pop => " << x << endl;
    }

    cout << "Dequeue from empty: " << (q.dequeue(x) ? "OK" : "Fail") << endl;

    cout << endl << endl;

    cout<<"==============================================="<<endl;
    cout<<"========== NGE test ======="<<endl;
int arr[] = {1, 3, 2, 4};
cout<<"original array = ";
for(int i=0 ; i<4 ; i++){
    cout<<arr[i]<<"  ";
}
cout<<endl;
int Size = 4;

int* result = NGE(arr, Size);

for (int i = 0; i < Size; i++)
    cout << result[i] << " ";
    cout<<endl<<endl;
    cout<<"==============================================="<<endl;
    cout<<"========== reverse queue test test ======="<<endl;
    cout<<endl;
    Queue_linked q3(5);
    cout<<"original queue = ";
    for (int i =1 ; i<6;i++){
        cout<<i*10<<"  ";
        q3.enqueue(i*10);
    }
    cout<<endl;
    q3.reverseQueue();
    int val3=0;
    cout<<"Reversed Queue = " ;
        for (int i =1 ; i<6;i++){

        q3.dequeue(val3);
        cout<<val3<<"  ";

    }
    return 0;
}
