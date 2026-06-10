// Generate All Permutations - O(n! * n) Time and O(n! * n) Space
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<vector<int>> &res,
                          vector<int> &arr, int idx)
{

    // Base case: if idx reaches the end of array
    if (idx == arr.size() - 1)
    {
        res.push_back(arr);
        return;
    }

    // Generate all permutations by swapping
    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[idx], arr[i]);

        // Recur for the next index
        generatePermutations(res, arr, idx + 1);

        // Backtrack to restore original array
        swap(arr[idx], arr[i]);
    }
}

// Function to find the next permutation
void nextPermutation(vector<int> &arr)
{

    vector<vector<int>> res;

    // Generate all permutations
    generatePermutations(res, arr, 0);

    // Sort all permutations lexicographically
    sort(res.begin(), res.end());

    // Find the current permutation index
    for (int i = 0; i < res.size(); i++)
    {

        // If current permutation matches input
        if (res[i] == arr)
        {

            // If it's not the last permutation
            if (i < res.size() - 1)
            {
                arr = res[i + 1];
            }

            // If it's the last permutation
            else
            {
                arr = res[0];
            }

            break;
        }
    }
}

int main()
{

    vector<int> arr = {2, 4, 1, 7, 5, 0};

    nextPermutation(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}