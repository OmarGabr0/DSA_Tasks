#include <iostream>

using namespace std;
void bubblesort(int arr[] , int Size){
    int temp =0 ;
    int sd=1;
    for(int i = 0 ; i<Size-1 ; i++){
        sd=1 ;
        for (int j=0;j<Size-i-1;j++){
                if(arr[j]>arr[j+1]){
                    temp = arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                    sd=0;
                }

        }
        if(sd==1) break;
            // i mean if it still 1 so it never entered the loop then quit
    }

}
int main()
{
   int arr[5]={2,3,1,5} ;

    bubblesort(arr,4);
    cout<<"arr = ";
    for(int i = 0 ; i<4 ; i++){
        cout<<"\t"<<arr[i];
    }
    cout<<endl;
    return 0;
}
