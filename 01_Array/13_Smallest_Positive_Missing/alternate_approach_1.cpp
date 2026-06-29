// By Negating Array Elements – O(n) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr)
{
    int pivotIdx = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        // Move positive elements to the left
        if (arr[i] > 0)
        {
            swap(arr[i], arr[pivotIdx]);
            pivotIdx++;
        }
    }

    // return index of the first non-positive number
    return pivotIdx;
}

int missingNumber(vector<int> &arr)
{
    int k = partition(arr);

    // Traverse the positive part of the array
    for (int i = 0; i < k; i++)
    {

        // Find the absolute value to get the original number
        int val = abs(arr[i]);

        // If val is within range, then mark the element at
        // index val-1 to negative
        if (val - 1 < k && arr[val - 1] > 0)
        {
            arr[val - 1] = -arr[val - 1];
        }
    }

    // Find first unmarked index
    for (int i = 0; i < k; i++)
    {

        if (arr[i] > 0)
        {
            return i + 1;
        }
    }

    // If all numbers from 1 to k are marked
    // then missing number is k + 1
    return k + 1;
}

int main()
{

    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr);
    return 0;
}