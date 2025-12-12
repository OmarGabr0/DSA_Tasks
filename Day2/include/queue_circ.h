#ifndef QUEUE_CIRC_H
#define QUEUE_CIRC_H


class queue_circ
{
    public:
        queue_circ(int S){
        fron = -1;
        rear = -1;
        Size = S;
        arr=new int [Size];
        }

       bool enqueue(int val){
        if (isFull()){
            return false;
        }

        if (fron == -1){
            fron = 0;}

        rear = (rear + 1) % Size;
        arr[rear] = val;
        return true;
        }

    bool dequeue(int &val)
    {
        if (isEmpty())
            return false;

        val = arr[fron];

        // Only one element
        if (fron == rear)
        {
            fron = -1;
            rear  = -1;
        }
        else
        {
            fron = (fron + 1) % Size;
        }
        return true;
    }


       // virtual ~queue_circ();

    protected:

    private:
        int fron;
        int rear ;
        int Size ;
        int * arr ;
        bool isFull(){
            if(rear==-1){ // to handle case 0 when first increment
                return false;
            }
            else if ( ( rear+1 )%Size == fron){ // case fron =0 first iti , rear = size and about to enter secone ititr
                return true;
           } else{
                return false;
            }
        }

    bool isEmpty()
    {
        return (fron == -1);
    }

};

#endif // QUEUE_CIRC_H
