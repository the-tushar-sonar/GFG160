#include <bits/stdc++.h>
using namespace std;

/*
// Brute Force
int maxProduct(vector<int> &arr)
{
    int maxP = arr[0];
    int minP = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        int currProd = 1;

        for (int j = i; j < arr.size(); j++)
        {
            currProd = currProd * arr[j];
            maxP = max(maxP, currProd);
            minP = min(minP, currProd);
            if (currProd == 0)
            {
                currProd = 1;
            }

            // cout << arr[j] << " ";
            // cout << currProd << " ";
        }
        // cout << endl;
        // cout << "Max Product is : " << maxP << endl;
        // cout << "Min Product is : " << minP << endl;
    }
    return maxP;
}
*/

// Optimal Approach => O(n) time & O(1) space
int maxProduct(vector<int> &arr)
{
    int n = arr.size();
    int maxEnding = arr[0];
    int minEnding = arr[0];
    int ans = arr[0];
    // cout << "i\t" << "arr[i]\t" << "Max\t" << "Min" << endl;
    for (int i = 1; i < n; i++)
    {
        int prevMax = maxEnding;
        int prevMin = minEnding;

        maxEnding = max({arr[i], (prevMax * arr[i]), (prevMin * arr[i])});
        minEnding = min({arr[i], (prevMax * arr[i]), (prevMin * arr[i])});
        // cout << i << "\t" << arr[i] << "\t" << maxEnding << "\t" << minEnding << endl;

        ans = max(ans, maxEnding);
    }

    // cout << "Max : " << ans << endl;
    return ans;
}

struct TestCase
{
    vector<int> arr;
    int expected;
};

int main()
{
    /*
     */
    vector<TestCase> testCases = {

        // Given examples
        {{-2, 6, -3, -10, 0, 2}, 180},
        {{-1, -3, -10, 0, 6}, 30},
        {{2, 3, 4}, 24},

        // Single element
        {{5}, 5},
        {{-5}, -5},
        {{0}, 0},

        // All positives
        {{1, 2, 3, 4}, 24},
        {{10, 2, 5}, 100},

        // All negatives - even count
        {{-1, -2}, 2},
        {{-1, -2, -3, -4}, 24},

        // All negatives - odd count
        {{-1, -2, -3}, 6},
        {{-2, -3, -4}, 12},

        // Zero splits array
        {{-2, 0, -1}, 0},
        {{0, 2, 3}, 6},
        {{2, 3, 0, 4, 5}, 20},

        // Maximum product in middle
        {{2, -5, -2, -4, 3}, 24},
        {{-2, 3, -4}, 24},

        // Famous interview cases
        {{2, 3, -2, 4}, 6},
        {{-2, 3, -4}, 24},

        // Multiple zeros
        {{0, 0, 0}, 0},
        {{0, -2, -3, 0, -4, -5}, 20},

        // Large negative becomes maximum later
        {{-2, 3, -4, -5}, 60},
        {{1, -2, -3, 4}, 24},

        // Product resets after zero
        {{-1, -2, -3, 0, 7, -8, -2}, 112},

        // Maximum is single element
        {{-5, 0, -2}, 0},
        {{-10, 2}, 2},

        // Alternating signs
        {{1, -2, 3, -4, 5}, 120},
        {{-1, 2, -3, 4, -5, 6}, 720},

        // Boundary-style values
        {{100, 100}, 10000},
        {{-100, -100}, 10000},
        {{100, -100, -100}, 1000000},

        // Entire array is answer
        {{-1, -2, -3, -4}, 24},
        {{2, -3, 4, -5}, 120},

        {{-2, 6, -3, -10, 0, 2, 5, 0, -2, -20}, 180},
        {{0, 0, 0, 0, -2, -10}, 20},
    };
    for (auto &test : testCases)
    {
        int ans = maxProduct(test.arr);

        if (ans == test.expected)
            cout << "PASS\n";
        else
            cout << "FAIL Expected: "
                 << test.expected
                 << " Got: "
                 << ans
                 << "\n";
    }

    // vector<int> arr = {-2, 6, -3, -10, 0, 2};
    // vector<int> arr = {-2, 6, -3, -10, 0, 2, 5, 0, -2, -20};
    // maxProduct(arr);

    return 0;
}