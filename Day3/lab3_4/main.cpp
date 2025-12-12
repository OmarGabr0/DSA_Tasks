#include <iostream>
using namespace std;

void merg(int* arr, int LF, int RE) {

    int m = (LF + RE) / 2;

    int s1 = m - LF + 1;
    int s2 = RE - m;

    int* L = new int[s1];
    int* R = new int[s2];

    for(int i = 0; i < s1; i++)
        L[i] = arr[LF + i];


    for(int j = 0; j < s2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = LF;


    while(i < s1 && j < s2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < s1)
        arr[k++] = L[i++];

    while(j < s2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}


void mergSort(int* arr, int LF, int RE) {

    if(LF >= RE)
        return;

    int m = (LF + RE) / 2;

    mergSort(arr, LF, m);
    mergSort(arr, m + 1, RE);

    merg(arr, LF, RE);
}

int main() {

    int arr[] = {9, 3, 7, 1, 4, 2};
    int n = 6;

    mergSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
