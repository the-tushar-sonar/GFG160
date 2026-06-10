#include <bits/stdc++.h>
using namespace std;

// Brute Force --> O(n²) time & O(1) space
vector<int> findMajority(vector<int> &arr)
{
    int n = arr.size();
    int limit = n / 3;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        auto it = find(ans.begin(), ans.end(), arr[i]);

        if (it != ans.end())
            continue;

        int count = 0;

        for (int j = 0; j < n; j++)
        {

            if (arr[i] == arr[j])
            {
                count++;

                if (count > limit)
                {
                    ans.push_back(arr[i]);
                    break;
                }
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{

    vector<int> arr1 = {2, 2, 3, 1, 3, 2, 1, 1};
    findMajority(arr1);
    vector<int> arr2 = {5};
    findMajority(arr2);
    vector<int> arr3 = {7, 7};
    findMajority(arr3);
    vector<int> arr4 = {7, 8};
    findMajority(arr4);
    vector<int> arr5 = {1, 2, 3, 4, 5, 6};
    findMajority(arr5);
    vector<int> arr6 = {1, 1, 1, 2, 3, 4};
    findMajority(arr6);
    vector<int> arr7 = {1, 1, 1, 2, 2, 2, 3};
    findMajority(arr7);
    vector<int> arr8 = {9, 9, 9, 9, 9};
    findMajority(arr8);
    vector<int> arr9 = {-5, 3, -5};
    findMajority(arr9);
    vector<int> arr10 = {-1, -1, -1, 2, 2, 3};
    findMajority(arr10);
    vector<int> arr11 = {1, 1, 2, 2, 3, 3};
    findMajority(arr11);
    vector<int> arr12 = {1, 2, 3, 4, 4, 4, 4};
    findMajority(arr12);
    vector<int> arr13 = {5, 5, 5, 5, 1, 2, 3};
    findMajority(arr13);
    vector<int> arr14 = {2, 2, 2, 1, 1, 1, 3};
    findMajority(arr14);
    vector<int> arr15 = {1, 1, 1, 2, 2, 2, 3, 4};
    findMajority(arr15);
    vector<int> arr16 = {1, 2, 3, 1, 2, 3, 1, 2};
    findMajority(arr16);

    return 0;
}