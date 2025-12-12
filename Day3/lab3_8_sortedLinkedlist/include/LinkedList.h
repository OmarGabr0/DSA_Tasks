#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;
class LinkedList
{
    public:



        LinkedList()
        {
            head = tail = nullptr;
        }
/// keeb moving if data > current data
        void add(int data)  // O(1)
        {
            // insert new node
            Node * current = head;

            if(head == nullptr) /// handling first node insertion at all
            {
                Node * node = new Node(data);

                head = tail = node;

            }
            else
            {
                if(current==tail){ /// if only one node , the head excite
                    if( head->data > data ){ /// if the data < head then iserst before it ,
                                              /// insert before and afteer will handel the head pointer to new position
                        insertBefore(head->data,data);
                    }else{
                        insertAfter(head->data,data) ;
                    }
                } else { /// if there is multi nodes
                    while(current->data < data ){ /// keeb moving if data > current data
                        /// keeb moving if data > current data current=current->next; // point to next node

                        if(current->next==nullptr){ /// handling case that current is the last node
                            insertAfter(current->data,data);
                            return;

                        }
                        current=current->next;
                    }
                    /// we exit the loop when the node im standing in is the first node
                    /// that have data larger than i want to insert
                    /// so i'll insert before it
                    insertBefore(current->data,data);
                }


            }

        }


        // for testing
        void Display()  // O(n)
        {

            Node * current = head;
            // Loop
            while(current!= nullptr)
            {
                // print data
                cout<<current->data<<"\t";

                //move next
                current = current->next;

            }
        }

        bool Search(int data)
        {
            // getNode(Data)
            if(getNode(data)!=nullptr)
                return true;
            else return false;
        }


        bool Delete(int data)
        {
            // search
            Node * node = getNode(data);
            if(node!=nullptr)
            {
                // delete
                //one element
                if(head == node && tail == node)
                {
                    head = tail = nullptr;
                }

                // head
                else if(node == head)
                {
                    head = node->next;
                    head->prev = nullptr;
                }

                // tail
                else if(node == tail)
                {
                     tail = node->prev;
                     tail->next = nullptr;
                }

                // inbetween
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                delete node;

            }
            else return false;
        }
        void insertAfter (int data,int  afterData) {

            Node * current = getNode(data);

            if (current == nullptr) return;
            Node * node=new Node(afterData);
            if(current->next==nullptr){ // if the last node

                node->next=nullptr;
                node->prev=tail;

                tail->next=node;
                tail=node;

            } else {
                node->next=current->next;
                node->prev=current;
                current->next->prev = node;
                current->next=node;
            }

        }

        void insertBefore (int data, int  beforeData) {

            Node * current = getNode(data) ;
            if(current==nullptr) return ;
            Node * node = new Node(beforeData) ;
            if(current->prev==nullptr) { // the first node
                node->prev=nullptr;
                node->next=head;

                head->prev=node;
                head=node;

            }else {
                current->prev->next=node;
                node->prev=current->prev;
                node->next=current;
                current->prev=node;

            }

        }

        int count() {
            Node * current = head;
            int c=0;


            while (current != nullptr) {
                c++;
                current = current->next;
            }
            return c ;
        }

        int getDataByIndex(int index) {
            Node * current = head ;
            for (int i =0 ; i<index ; i++){
                    current =current->next;
                if(current == nullptr ){
                    cout<<"Error: value not found"<<endl;
                    return -1 ;
                }
            }
            return current->data ;

        }

        void reverse() {

            Node * current = head ;

            Node* temp1=nullptr;
            Node * temp2 = head;

            while (current != nullptr){

                temp1=current->prev;
                current->prev=current->next;
                current->next=temp1;
                current=current->prev;
            }

            head=tail ;
            tail = temp2;

        }

        LinkedList reversenew() {
            LinkedList newlist;
            Node* current = head;


            while (current != nullptr) {
                newlist.add(current->data);
                current = current->next;
            }

            return newlist;
        }


        void removekth(int k ){
            if(k<=0) return;

            int n =1 ;
            Node * current = head;
            Node * nextnode=nullptr;

            while( current !=nullptr){
                nextnode=current->next;

            if(n%k==0){

                if (current == head) {
                    head = current->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                    else
                        tail = nullptr; // list became empty
                } else if (current == tail ) {
                           tail=current->prev;
                            //if single node = head only
                                if(tail!=nullptr){
                                    tail->next=nullptr;
                                } else {
                                    head=nullptr;
                                }

                            }else {

                                current->prev->next=current->next;
                                current->next->prev=current->prev;

                            }
                            delete current;
                    }
                current=nextnode;
                n+=1;

            }


        }

        LinkedList intersection ( const LinkedList& l2 ){
            LinkedList l3 ;

            Node * current1=this->head;
            Node * current2=nullptr;

            while (current1 != nullptr) {
             current2 = l2.head;

                while (current2 != nullptr) {
                    if (current1->data == current2->data) {
                        l3.add(current1->data);
                        break;
                    }
                    current2 = current2->next;
                }

                current1 = current1->next;
            }
            return l3;

        }
        /// function to help in pop from stack
        bool deleteTail()
        {
            Node * current = tail ;
            if(current!=nullptr){
                // only one node
                if(head==tail){
                    head=nullptr;
                    tail=nullptr;

                } else { //node from middle
                    current->prev->next=nullptr;
                    tail=current->prev;
                }
                delete current ;
            }else {
            return false;
            }
        }
        ///   function to delete head for queue using linkedlist
        bool deleteHead(){

            Node * current = head ;
            if(current !=nullptr){
                if(tail == head ){
                    tail = nullptr;
                    head = nullptr;
                } else {
                    head= current->next ;
                    head->prev=nullptr;
                }
                delete current ;
            } else {
                return false ;
            }
        }

        /// function to shift  after pop from front
        void shift_backword ( ){

            Node * current =head;
            while(current->next != nullptr){
                current->data = current->next->data;
                current=current->next;
            }

        }



    private:
        Node * head;
        Node * tail;

    Node* getNode(int data)
    {
        Node * current = head;
        while(current != NULL)
        {
            // found
            if(data == current->data)
                return current;
            //move next
            current = current->next;
        }
        return NULL;
    }
};

#endif // LINKEDLIST_H
