#include <iostream>
using namespace std;

void sortByFrequency(int arr[], int n)
{
    int values[100];
    int freq[100];
    int uniqueCount = 0;


    for (int i = 0; i < n; i++)
    {
        int found = -1;

        for (int j = 0; j < uniqueCount; j++)
        {
            if (values[j] == arr[i])
            {
                found = j;
                break;
            }
        }

        if (found == -1)  /// new element
        {
            values[uniqueCount] = arr[i];
            freq[uniqueCount] = 1;
            uniqueCount++;
        }
        else  ///increase the freq
        {
            freq[found]++;
        }
    }

///sort
    for (int i = 0; i < uniqueCount - 1; i++)
    {
        for (int j = i + 1; j < uniqueCount; j++)
        {
            // Sort by frequency DESCENDING
            if (freq[i] < freq[j] ||
               (freq[i] == freq[j] && values[i] > values[j])) // same freq → smaller value first
            {
                // swap frequencies
                int tempF = freq[i];
                freq[i] = freq[j];
                freq[j] = tempF;

                // swap values
                int tempV = values[i];
                values[i] = values[j];
                values[j] = tempV;
            }
        }
    }

    // Step 3: Write back to original array
    int index = 0;
    for (int i = 0; i < uniqueCount; i++)
    {
        for (int j = 0; j < freq[i]; j++)
        {
            arr[index++] = values[i];
        }
    }
}

int main()
{
    int arr[] = {5, 5, 4, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    sortByFrequency(arr, n);

    cout << "Output: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
