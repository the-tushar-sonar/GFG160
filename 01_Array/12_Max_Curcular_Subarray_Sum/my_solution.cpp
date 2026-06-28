#include <bits/stdc++.h>
using namespace std;

/*
int maxCircularSum(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = arr[0];
    int sum = arr[0];

    cout << "index\tvalue\tcurrSum\tstart\tend\tmaxSum" << endl;
    int start = 0;
    for (int i = 1; i < 2 * n; i++)
    {
        int idx = i % n;
        int end = idx;
        if (start == end)
        {
            // cout << "start and end are SAME...." << endl;
            sum = 0;
            // continue;
        }

        if (sum == 0)
        {
            start = idx;
            // cout << "start updated..." << endl;
        }

        sum += arr[idx];
        maxSum = max(maxSum, sum);
        // cout << arr[idx] << endl;
        cout << idx
        << "\t" << arr[idx] << "\t" << sum << "\t" << start << "\t" << end << "\t" << maxSum << endl;
        if (sum < 0)
        {

        sum = 0;

        }

    }
    cout << "circularMax : " << maxSum << endl;

    return maxSum;
}
*/

/*
Single element
All positive
All negative
Single Kadane's is Efficient

*/

int maxCircularSum(vector<int> &arr)
{
    int totalSum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    int sum = 0;
    int negativeCount = 0;
    int n = arr.size();

    // NORMAL KADANE'S
    for (int num : arr)
    {

        sum += num;
        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    int kadaneMax = maxSum;

    // TOTAL SUM
    for (int num : arr)
    {
        if (num < 0)
            negativeCount++;

        totalSum += num;
    }

    sum = 0;

    // MIN SUB ARRAY
    for (int num : arr)
    {
        sum += num;
        minSum = min(minSum, sum);
        if (sum > 0)
        {
            sum = 0;
        }
    }
    int circularMax = totalSum - minSum;

    // ALL NEGATIVE
    if (n == negativeCount)
        return kadaneMax;

    return max(kadaneMax, circularMax);
}

struct TestCase
{
    vector<int> arr;
    int expected;
};

int main()
{
    // cout << "N Kdn\tTtl\tMinSum\tcircularMax" << endl;
    /*
     */
    vector<TestCase> testCases = {
        // Single element
        {{5}, 5},
        {{-5}, -5},

        // All positive
        {{1, 2, 3, 4}, 10},

        // All negative
        {{-1, -2, -3, -4}, -1},

        // Given examples
        {{8, -8, 9, -9, 10, -11, 12}, 22},
        {{10, -3, -4, 7, 6, 5, -4, -1}, 23},
        {{5, -2, 3, 4}, 12},

        // Normal Kadane is better
        {{2, -1, 2, 3, -9}, 6},
        {{4, -1, 2, 1}, 7},

        // Circular is better
        {{3, -2, 2, -3}, 3},
        {{8, -1, 3, 4}, 15},
        {{9, -4, -7, 9}, 18},

        // Remove minimum subarray
        {{5, -3, 5}, 10},
        {{2, -2, 2, 7, 8, 0}, 19},

        // Large negative in middle
        {{10, -100, 20, 30}, 60},

        // Zeros
        {{0, 0, 0}, 0},
        {{0, -2, 0}, 0},

        // Alternating signs
        {{1, -1, 1, -1, 1, -1}, 1},
        {{-2, 3, -2, 3, -2}, 4},

        // Wrap around using first and last
        {{100, -90, 20}, 120},
        {{50, -10, -10, 50}, 100},

        // Minimum subarray at beginning
        {{-5, -2, 8, 9}, 17},

        // Minimum subarray at end
        {{8, 9, -5, -2}, 17},

        // Entire array should be chosen
        {{2, 3, 1, 4}, 10},

        // Tricky
        {{1, -2, 3, -2}, 3},
        {{5, -5, 5}, 10},
        {{-3, 5, -2, 5, -3}, 8}};

    for (auto &test : testCases)
    {
        int ans = maxCircularSum(test.arr);

        if (ans == test.expected)
            cout << "PASS\n";
        else
            cout << "FAIL Expected: "
                 << test.expected
                 << " Got: "
                 << ans
                 << "\n";
    }

    // vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    // maxCircularSum(arr);
    // cout << endl;
    // vector<int> arr1 = {10, -3, -4, 7, 6, 5 - 4, -1};
    // maxCircularSum(arr1);
    // cout << endl;
    // vector<int> arr2 = {5, -2, 3, 4};
    // maxCircularSum(arr2);

    return 0;
}