#include <iostream>

using namespace std;

int Partition(int* arr, int Size)
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

    int p = Partition(arr, Size);

    // left side
    quickSort(arr, p);

    // right side
    quickSort(arr + p + 1, Size - p - 1);
}

void matrixSort(int **matr,int m ){
int * arr=new int[m*m];
int k=0;
/// get all matrix into array
for(int i =0 ;i<m;i++){
    for(int j=0;j<m;j++){
        arr[k++]=matr[i][j];
    }
}
/// sort the arr ;
quickSort(arr,m*m) ;
k=0;
for(int i = 0 ; i<m;i++){
    for(int j=0;j<m;j++){
        matr[i][j]=arr[k++];
    }
}
delete [] arr ;
}

int main()
{
    int m;
    cout << "Enter matrix size m: ";
    cin >> m;

    // Allocate matrix
    int** mat = new int*[m];
    for (int i = 0; i < m; i++)
        mat[i] = new int[m];

    // Input matrix
    cout << "Enter " << m*m << " values:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    // Print before sorting
    cout << "\nMatrix before sorting:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    // Sort entire matrix
    matrixSort(mat, m);

    // Print after sorting
    cout << "\nMatrix after sorting:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < m; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}
