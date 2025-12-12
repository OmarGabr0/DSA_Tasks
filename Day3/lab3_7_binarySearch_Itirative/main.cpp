#include <iostream>

using namespace std;

int binarySearch(int * arr,int val ,int LF,int RE){
    int I =0;
    int m=0;

    while(LF<=RE ){
        m=(LF+RE)/2;

        if(arr[m]>val){
            RE=m-1;
        }else if(arr[m]<val){
            LF=m+1;
        } else if(arr[m]=val){
            return m;
        }

    }
    cout<<" Value not in arr"<<endl;
    return -1;
}
int main()
{
    int arr [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};

    int val;
    cout<<"Enter value: ";
    cin>>val;

    int I;

    I=binarySearch(arr,val,0, 9);
   (I == -1)
    ? cout << "Error" << endl
    : cout << "Found in Index I= "<<I<<endl<<"arr[I] = " << arr[I] << endl;
/*
    cout<<"==================================="<<endl;
    cout<<"      value in the middle case     "<<endl;
    int arr2 [5] = {1, 2, 3, 4, 5};
    I=binarySearch(arr2,3,0, 4);
   (I == -1)
    ? cout << "Error" << endl
    : cout << "Found in Index I= "<<I<<endl<<"arr[I] = " << arr2 [I] << endl;
*/
    return 0;
}
