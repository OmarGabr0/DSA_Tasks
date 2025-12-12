#include <iostream>

using namespace std;
void InsertionSort(int * arr ,int Size ){
int temp =0 ;
    for(int j=0 ; j < Size-1 ; j++){

            for(int i=j;i<Size-j-1;i++){
                    if(arr[i]>arr[i+1]){
                        temp = arr[i+1];
                        arr[i+1]=arr[i];
                        arr[i]=temp;
                }
        }
    }

}
int main()
{

int arr[5]={2,3,1,5} ;

InsertionSort(arr,5);
cout<<"arr = ";
for(int i = 0 ; i<5 ; i++){
    cout<<"\t"<<arr[i];
}
cout<<endl;
    return 0;
}
