#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    int maxSum = INT_MIN;
    int sum = 0;

    for (int num : arr)
    {
        sum += num;
        maxSum = max(maxSum, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

struct TestCase
{
    vector<int> arr;
    int expected;
};

int main()
{

    // vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    // maxSubarraySum(arr);

    vector<TestCase> testCases = {
        // Given examples
        {{2, 3, -8, 7, -1, 2, 3}, 11},
        {{-2, -4}, -2},
        {{5, 4, 1, 7, 8}, 25},

        // Single element
        {{5}, 5},
        {{-5}, -5},
        {{0}, 0},

        // All positive
        {{1, 2, 3, 4, 5}, 15},
        {{10, 20, 30}, 60},

        // All negative
        {{-1, -2, -3, -4, -5}, -1},
        {{-8, -3, -6, -2, -5, -4}, -2},

        // All zeros
        {{0, 0, 0, 0}, 0},

        // Zeros mixed with negatives
        {{-2, 0, -1}, 0},
        {{0, -1, 0, -2, 0}, 0},

        // Maximum subarray in the middle
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{-10, 2, 3, 4, -1, 2, -5}, 10},

        // Maximum subarray at the beginning
        {{10, 5, -20, 1, 2}, 15},

        // Maximum subarray at the end
        {{-20, 1, 2, 10, 5}, 18},

        // Entire array is the answer
        {{1, 2, 3, -1, 2}, 7},
        {{2, -1, 2, 3, 4, -5}, 10},

        // Large negative causing reset
        {{4, 5, -100, 10, 20}, 30},
        {{100, -200, 300}, 300},

        // Alternating signs
        {{1, -1, 1, -1, 1, -1, 1}, 1},
        {{4, -1, 2, 1}, 6},
        {{-1, 2, -1, 2, -1, 2}, 4},

        // Multiple resets
        {{-2, 3, 2, -1, 4, -10, 5, 6}, 11},
        {{-5, 6, -2, 7, -15, 20}, 20},

        // Famous Kadane example
        {{-2, -3, 4, -1, -2, 1, 5, -3}, 7},

        // Boundary values
        {{10000, -10000, 10000}, 10000},
        {{-10000, 10000, -10000}, 10000},

        // Long positive streak after negatives
        {{-5, -4, -3, 1, 2, 3, 4, 5}, 15},

        // Multiple equal maximum subarrays
        {{1, -1, 1, -1, 1}, 1},
        {{2, -2, 2, -2, 2}, 2}};

    for (auto &test : testCases)
    {
        int ans = maxSubarraySum(test.arr);

        if (ans == test.expected)
            cout << "PASS\n";
        else
            cout << "FAIL Expected: "
                 << test.expected
                 << " Got: "
                 << ans
                 << "\n";
    }

    return 0;
}