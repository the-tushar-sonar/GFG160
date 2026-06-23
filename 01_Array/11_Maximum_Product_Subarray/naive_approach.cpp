// Using Two Nested Loops – O(n^2) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int> &arr)
{

    int n = arr.size();

    // Initializing result
    int maxProd = arr[0];

    for (int i = 0; i < n; i++)
    {
        int mul = 1;

        // traversing in current subarray
        for (int j = i; j < n; j++)
        {
            mul *= arr[j];

            // updating result every time
            // to keep track of the maximum product
            maxProd = max(maxProd, mul);
        }
    }
    return maxProd;
}

int main()
{

    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout << maxProduct(arr);
    return 0;
}