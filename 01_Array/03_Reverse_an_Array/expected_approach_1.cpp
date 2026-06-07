// Using Two Pointers - O(n) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr)
{

    // Initialize left to the beginning
    // and right to the end
    int left = 0, right = arr.size() - 1;

    // Iterate till left is less than right
    while (left < right)
    {

        // Swap the elements at left
        // and right position
        swap(arr[left], arr[right]);

        // Increment the left pointer
        left++;

        // Decrement the right pointer
        right--;
    }
}

int main()
{
    vector<int> arr = {1, 4, 3, 2, 6, 5};

    reverseArray(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}