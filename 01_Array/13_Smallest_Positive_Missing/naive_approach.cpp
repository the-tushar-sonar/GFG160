// By Sorting - O(n*log n) Time and O(1) Space
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &arr)
{

    sort(arr.begin(), arr.end());
    int res = 1;
    for (int i = 0; i < arr.size(); i++)
    {

        // If we have found 'res' in the array,
        // 'res' is no longer missing, so increment it
        if (arr[i] == res)
            res++;

        // If the current element is larger than 'res',
        // 'res' cannot be found in the array,
        // so it is our final answer
        else if (arr[i] > res)
            break;
    }
    return res;
}

int main()
{
    vector<int> arr = {2, -3, 4, 1, 1, 7};

    cout << missingNumber(arr);
    return 0;
}