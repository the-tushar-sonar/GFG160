// Generating Only Next - O(n) Time and O(1) Space
/*
Step-By-Step Approach:

- Iterate over the given array from end and find the first index (pivot) which doesn't follow property of non-increasing suffix, (i.e,  arr[i] < arr[i + 1]).
- If pivot index does not exist, then the given sequence in the array is the largest as possible. So, reverse the complete array. For example, for [3, 2, 1], the output would be [1, 2, 3]
- Otherwise, Iterate the array from the end and find for the successor (rightmost greater element) of pivot in suffix.
- Swap the pivot and successor
- Minimize the suffix part by reversing the array from pivot + 1 till n.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &arr)
{

    int n = arr.size();

    // Find the pivot index
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // If pivot point does not exist, reverse the
    // whole array
    if (pivot == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the element from the right that
    // is greater than pivot
    for (int i = n - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // Reverse the elements from pivot + 1 to the
    // end to get the next permutation
    reverse(arr.begin() + pivot + 1, arr.end());
}

int main()
{

    vector<int> arr = {2, 4, 1, 7, 5, 0};
    nextPermutation(arr);
    for (int x : arr)
        cout << x << " ";
    return 0;
}