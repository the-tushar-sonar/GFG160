// By Marking Indices – O(n) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &arr)
{

    int n = arr.size();
    bool flag = false;

    // Check if 1 is present in array or not
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            flag = true;
            break;
        }
    }

    // If 1 is not present
    if (flag == false)
        return 1;

    // Change out of range values to 1
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0 || arr[i] > n)
            arr[i] = 1;
    }

    // Mark the occurrence of numbers
    // directly within the same array
    for (int i = 0; i < n; i++)
    {
        arr[(arr[i] - 1) % n] += n;
    }

    // Finding which index has value less than n
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= n)
            return i + 1;
    }

    // If array has values from 1 to n
    return n + 1;
}

int main()
{
    vector<int> arr = {2, -3, 4, 1, 1, 7};

    cout << missingNumber(arr);
    return 0;
}