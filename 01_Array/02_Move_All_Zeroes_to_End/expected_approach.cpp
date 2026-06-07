// One Traversal-O(n) Time and O(1) space
#include <iostream>
#include <vector>
using namespace std;

void pushZerosToEnd(vector<int> &arr)
{

    // Pointer to track the position
    // for next non-zero element
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        // If the current element is non-zero
        if (arr[i] != 0)
        {

            // Swap the current element with
            // the 0 at index 'count'
            swap(arr[i], arr[count]);
            // Move 'count' pointer to the
            // next position
            count++;
        }
    }
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