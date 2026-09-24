// [Naive Approach] Two Nested Loops - O(n ^ 2) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int inversionCount(vector<int> &arr)
{

    int n = arr.size();
    int invCount = 0;

    // Loop through the array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            // If the current element is greater
            // than the next, increment the count
            if (arr[i] > arr[j])
                invCount++;
        }
    }

    return invCount;
}

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    cout << inversionCount(arr) << endl;
    return 0;
}