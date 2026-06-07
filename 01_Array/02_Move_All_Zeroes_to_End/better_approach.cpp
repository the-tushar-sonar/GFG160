// Two Traversals-O(n) Time and O(1) space
#include <iostream>
#include <vector>
using namespace std;

void pushZerosToEnd(vector<int> &arr)
{

    int count = 0;

    // If the element is non-zero, replace the element at
    // index 'count' with this element and increment count
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
            arr[count++] = arr[i];
    }

    // Now all non-zero elements have been shifted to
    // the front. Make all elements 0 from count to end.
    while (count < arr.size())
        arr[count++] = 0;
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (int num : arr)
    {
        cout << num << " ";
    }
    return 0;
}