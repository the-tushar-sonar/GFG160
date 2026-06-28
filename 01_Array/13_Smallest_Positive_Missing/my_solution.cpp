#include <bits/stdc++.h>
using namespace std;

/*
int missingPositive(vector<int> &arr)
{
    int n = arr.size() + 1;
    int nthSum = (n * (n + 1)) / 2;
    int sum = 0;

    for (int num : arr)
    {
        sum += num;
    }

    cout << nthSum - sum << endl;
    return 0;
    }
    */

int missingNumber(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= n && arr[i] >= 1)
        {
            if (arr[i] != (i + 1))
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
    }

    int i;
    for (i = 0; i < n; i++)
        if (arr[i] != i + 1)
            return i + 1;

    return i + 1;
}

// int missingNumber(vector<int> &arr)
// {
//     int n = arr.size();
//     int idx = 0;
//     while (arr[idx] <= n && arr[idx] >= 1)
//     {
//         if (idx + 1 != arr[idx])
//             swap(arr[idx], arr[arr[idx] - 1]);

//         if (idx + 1 == arr[idx])
//             idx++;
//     }

//     return 0;
// }

struct TestCase
{
    vector<int> arr;
    int expected;
};

int main()
{

    vector<TestCase> tests = {
        // Basic examples
        {{2, -3, 4, 1, 1, 7}, 3},
        {{5, 3, 2, 5, 1}, 4},
        {{-8, 0, -1, -4, -3}, 1},

        // Single element
        {{1}, 2},
        {{2}, 1},
        {{0}, 1},
        {{-1}, 1},

        // Already consecutive
        {{1, 2, 3, 4, 5}, 6},
        {{1, 2, 3}, 4},

        // Missing at beginning
        {{2, 3, 4}, 1},
        {{7, 8, 9, 10}, 1},

        // Missing in middle
        {{1, 2, 4, 5}, 3},
        {{2, 1, 5, 4}, 3},
        {{3, 4, -1, 1}, 2},

        // Missing at end
        {{1, 2, 3, 5}, 4},

        // Duplicates
        {{1, 1, 2, 2}, 3},
        {{1, 1, 1, 1}, 2},
        {{2, 2, 2, 2}, 1},
        {{1, 2, 2, 3, 3}, 4},

        // Only negatives and zeros
        {{-1, -2, -3}, 1},
        {{0, 0, 0}, 1},
        {{-1, 0, -2, 0}, 1},

        // Mixed values
        {{2, 3, 7, 6, 8, -1, -10, 15}, 1},
        {{1, 1000, 2, 5000}, 3},
        {{100, 101, 102}, 1},
        {{1, 100, 2, 4}, 3},

        // Large irrelevant values
        {{1000000, 999999, 1}, 2},
        {{1000000, -1000000, 2}, 1},

        // Unsorted
        {{4, 3, 2, 7, 8, 2, 3, 1}, 5},
        {{5, 4, 3, 2, 1}, 6},
        {{5, 1, 2, 3, 4}, 6},

        // Edge cases
        {{1, 2}, 3},
        {{2, 1}, 3},
        {{2, 3}, 1},
        {{3, 1}, 2},
        {{1, 3}, 2}};

    int count = 0;
    for (auto &test : tests)
    {
        int ans = missingNumber(test.arr);
        cout << ++count << endl;

        if (ans == test.expected)
            cout << "PASS\n";
        else
            cout << "FAIL Expected: "
                 << test.expected
                 << " Got: "
                 << ans
                 << "\n";

        cout << endl;
    }

    // vector<int> arr = {2, -3, 4, 1, 1, 7};
    // missingNumber(arr);

    // vector<int> arr1 = {5, 3, 2, 5, 1};
    // missingNumber(arr1);

    // vector<int> arr2 = {-8, 0, -1, -4, -3};
    // missingNumber(arr2);

    return 0;
}