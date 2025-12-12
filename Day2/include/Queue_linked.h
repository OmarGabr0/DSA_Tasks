#ifndef QUEUE_LINKED_H
#define QUEUE_LINKED_H
#include "LinkedList.h"

class Queue_linked
{
    public:
        Queue_linked(int S){
            Size = S ;
            rear = -1;
            fron = 0 ;
        }

        bool enqueue(int val){
            if(isFull()){ return false ;
            } else {
                L.add(val);
                rear++;
                return true;

            }
        }

        bool dequeue(int &val){
            if(isEmpty()) {return false ;
            } else {
                val=L.getDataByIndex(fron);
                rear --;
                L.shift_backword();
                L.deleteTail();
            return true;

            }
        }
        void reverseQueue(){
        L.reverse();
        }

     //   virtual ~Queue_linked();

    protected:

    private:
        int Size ;
        int rear;
        int fron;

        LinkedList L ;

        bool isEmpty(){
            if(rear == -1) return true;
            else return false;
        }
        bool isFull(){
            if(rear == Size-1) return true;
            else return false ;
        }
};

#endif // QUEUE_LINKED_H
