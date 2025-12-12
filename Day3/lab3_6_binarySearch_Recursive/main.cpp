#include <iostream>


using namespace std;
int binarySearch(int * arr,int val ,int LF,int RE){

    int m = (LF+RE)/2;
    int I=0;
    if(LF>RE){
        cout<<"value not found"<<endl;
        return -1;
    }

    if(arr[m]==val){
            return I=m;
    } else if(arr[m]<val) {
        binarySearch(arr,val,m+1,RE);
    } else {                     //if(arr[m]>val)
        binarySearch(arr,val,LF,m-1);
    }



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
    return 0;
}
