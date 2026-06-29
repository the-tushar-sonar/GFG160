// Considering All Possible Subarrays – O(n ^ 2) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int maxCircularSum(vector<int> &arr)
{
    int n = arr.size();
    int res = arr[0];

    // Subarray that starts with index i
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;

        // Considering all possible endpoints of the
        // Subarray that begins with index i
        for (int j = 0; j < n; j++)
        {

            // Circular index
            int idx = (i + j) % n;
            currSum = currSum + arr[idx];
            res = max(res, currSum);
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << maxCircularSum(arr);
}