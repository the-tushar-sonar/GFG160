#include <bits/stdc++.h>
using namespace std;

// int getMinDiff(vector<int> &arr, int k)
// {
//     int minX = INT_MAX;
//     int maxX = INT_MIN;
//     int ans = 0;

//     for (int x : arr)
//     {
//         if (x > k)
//         {
//             x -= k;
//         }
//         else
//         {
//             x += k;
//         }
//         // cout << x << " ";

//         minX = min(minX, x);
//         maxX = max(maxX, x);
//     }
//     // cout << endl;
//     ans = maxX - minX;

//     // cout << "Solution: " << ans << endl;
//     return ans;
// }

// int getMinDiff(vector<int> &arr, int k)
// {
//     int minX = INT_MAX;
//     int maxX = INT_MIN;
//     int ans = 0;

//     int mid = arr.size() / 2;
//     int diff = arr[arr.size() - 1] - arr[0];
//     // cout << "K : " << k << "\tDiff : "
//     //      << diff << endl;
//     // cout << mid << endl;

//     if (diff <= k)
//     {
//         for (int i = 0; i < arr.size(); i++)
//         {
//             arr[i] += k;
//             minX = min(minX, arr[i]);
//             maxX = max(maxX, arr[i]);
//         }

//         ans = maxX - minX;

//         return ans;
//     }

//     for (int i = 0; i < arr.size(); i++)
//     {
//         // cout << arr[i] << " ";

//         if (i >= mid)
//         {
//             if (arr[i] > k)
//                 arr[i] -= k;
//         }

//         else
//         {
//             arr[i] += k;
//         }
//         minX = min(minX, arr[i]);
//         maxX = max(maxX, arr[i]);
//     }
//     // cout << endl;
//     for (int x : arr)
//     {
//         // cout << x << " ";
//     }
//     // cout << endl;
//     // cout << "Min : " << minX << "\tMax : " << maxX << endl;
//     ans = maxX - minX;

//     // cout << "Solution: " << ans << endl;

//     return ans;
// }

int getMinDiff(vector<int> &arr, int k)
{
    int minX = INT_MAX;
    int maxX = INT_MIN;
    int n = arr.size();
    int ans = 0;
    int fAns = INT_MAX;

    int diff = arr[n - 1] - arr[0];

    if (diff <= k)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] += k;
            minX = min(minX, arr[i]);
            maxX = max(maxX, arr[i]);
        }

        ans = maxX - minX;
        // cout << "Solution: " << ans << endl;

        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] - k >= 0 && arr[n - 1] - k >= 0)
        {
            minX = min(arr[0] + k, arr[i + 1] - k);
            maxX = max(arr[i] + k, arr[n - 1] - k);
            // cout
            //     << "Min : " << minX << "\tMax : " << maxX << endl;
            ans = maxX - minX;
            fAns = min(fAns, ans);
            // cout << "Solution: " << ans << endl;
        }
    }
    // cout << endl;
    // cout << "Final : " << fAns << endl;
    if (diff < fAns)
        return diff;

    return fAns;
}

struct TestCase
{
    vector<int> arr;
    int k;
    int expected;
};

int main()
{
    /*
     */
    vector<TestCase> tests = {
        {{10}, 5, 0},                    // Single tower
        {{1, 5, 8, 10}, 2, 5},           // Example 1
        {{3, 9, 12, 16, 20}, 3, 11},     // Example 2
        {{7, 7, 7, 7}, 4, 0},            // All equal
        {{1, 2, 3}, 10, 2},              // All elements < k
        {{2, 6, 10}, 5, 6},              // Some elements cannot be decreased
        {{4, 5, 6}, 2, 2},               // Close values
        {{1, 100}, 5, 89},               // Two elements, large gap
        {{1, 2, 3, 4, 5}, 3, 4},         // Increasing sequence
        {{1, 1, 1, 10, 10, 10}, 2, 5},   // Duplicates
        {{5, 10, 15}, 5, 5},             // Minimum element == k
        {{1, 50, 100}, 100, 99},         // Large k
        {{4, 8}, 4, 4},                  // Two elements
        {{1, 15, 20}, 6, 7},             // Large reduction possible
        {{1, 5, 8, 10}, 6, 9},           // Common tricky case
        {{1, 4, 7, 10}, 3, 3},           // Perfect balancing
        {{1, 10, 14, 14, 14, 15}, 6, 5}, // Duplicates + partition
        {{2, 3, 4, 5, 6}, 2, 3},         // Small consecutive values
        {{10000000}, 10000000, 0},       // Constraint boundary
        {{1, 10000000}, 1, 9999997}      // Large values
    };

    for (auto &test : tests)
    {
        int ans = getMinDiff(test.arr, test.k);

        if (ans == test.expected)
            cout << "PASS\n"
                 << endl;
        else
            cout << "FAIL Expected: "
                 << test.expected
                 << " Got: "
                 << ans
                 << "\n"
                 << endl;
    }

    // vector<int> arr = {1, 2, 3, 4, 5};
    // int k = 3;
    // getMinDiff(arr, k);

    return 0;
}