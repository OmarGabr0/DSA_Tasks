#include <iostream>

using namespace std;
int partition(int* arr, int Size)
{

    int pivot=arr[Size-1];

    int i =-1 ;
    int j = 0 ;
    int temp =0 ;
    while (j < Size - 1)
    {

        if(arr[j]<pivot)
        {
            i++;
            temp = arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }

        j++ ;
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[Size - 1];
    arr[Size - 1] = temp;

    return i + 1;


}



void quickSort(int* arr, int Size)
{
    if (Size <= 1)
        return;

    int p = partition(arr, Size);

    // left side
    quickSort(arr, p);

    // right side
    quickSort(arr + p + 1, Size - p - 1);
}

int main()
{
    int arr[] = {9, 3, 1, 7, 5, 2};
    quickSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
