#include <iostream>

using namespace std;
    void SelectionSort(int * arr , int Size ){
        int temp =0 ;
        int index=0;
        int last=0;

        for(int i =0 ; i<Size;i++){
                index =0;
           for(int j=0 ; j<Size-i;j++){
                if(arr[index]<arr[j]){
                    index=j;
                }
                last=j;
            }

                temp=arr[last];
                arr[last]=arr[index];
                arr[index]=temp;


        }
    }
int main()
{
   int arr[5]={2,5,3,1} ;

    SelectionSort(arr,4);
    cout<<"arr = ";
    for(int i = 0 ; i<4 ; i++){
        cout<<"\t"<<arr[i];
    }
    cout<<endl;
    return 0;
}
