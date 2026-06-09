#include <bits/stdc++.h>
#include <span>
using namespace std;

void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int x = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            x = i;
            break;
        }
    }
    // cout << "x : " << x << endl;
    // cout << "value at x : " << arr[x] << endl;

    if (x == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    int target = arr[x];
    int answer = INT_MAX;
    int answerIndex;

    for (int i = x + 1; i < n; i++)
    {
        if (arr[i] > target && arr[i] < answer)
        {
            answer = arr[i];
            answerIndex = i;
        }
    }
    // cout << "Exact Greater : " << answer << endl;
    swap(arr[x], arr[answerIndex]);
    // cout << "SWAP : ";
    // for (int x : arr)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    sort(arr.begin() + (x + 1), arr.end());
    // cout << "SORT : ";
    // for (int x : arr)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
}

int main()
{

    vector<int> arr = {62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22};
    // vector<int> arr = {3, 2, 1};
    // vector<int> arr = {3, 4, 2, 5, 1};
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    nextPermutation(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}