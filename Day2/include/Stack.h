#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack
{
    public:
        Stack(int S){
            Size=S;
            top = -1;
        }

        bool push(int val){
            if(isFull()){
                return false ;
            } else {
                L.add(val);
                top ++ ;
                return true;
            }
        }


        bool pop(int & val ){
            if(isEmpty() ){return false;}
            else {
                val=L.getDataByIndex(top);
                L.deleteTail();
                top -- ;
                return true;
            }
        }

        bool peak(int & val) {
            if(isEmpty()){return false;}
            else {
                val=L.getDataByIndex(top);
                return true;

            }
        }



      //  virtual ~Stack();

    protected:

    private:
        LinkedList L ;
        int Size;
        int top;

        bool isFull(){
            if(top==Size-1) return true;
            else return false ;
        }

        bool isEmpty(){
            if(top==-1) return true;
            else return false ;
        }

};

 int* NGE(int  arr[]  ,int  Size){
     Stack st(Size);
     int* nge =new int [Size];
     int val;
     // filling the stack

    for(int i =Size-1 ; i>= 0 ; i--){
            if(!st.push(arr[i])) break ;
         }
    int j=0;
    while(st.pop(val)){

        for ( int i =j ; i<Size ; i++){

           if(arr[i]> val) {
                nge[j]=arr[i] ;
           break ;
           }else if (i+1==Size){
                nge[j]=-1 ;
           }
        }
        j++;
    }
        return nge;

 }

#endif // STACK_H
