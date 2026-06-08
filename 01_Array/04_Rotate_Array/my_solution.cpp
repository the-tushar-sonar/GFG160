#include <bits/stdc++.h>
using namespace std;

// Temporary Array
// Time Complexity => O(n), Space Complexity => O(n)
/*
void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();
    d %= n;

    vector<int> temp(arr.begin(), arr.begin() + d);

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    copy(temp.begin(), temp.end(), arr.begin() + (n - d));
}
*/

// Repeated Left Shift
// Time Complexity => O(n^2), Space Complexity => O(1)
/*
void rotateArr(vector<int> &arr, int d)
{
    for (int i = 0; i < d; i++)
    {
        int n = arr.size();
        int temp = arr[0];
        for (int j = 1; j < n; j++)
        {
            arr[j - 1] = arr[j];
        }
        arr[n - 1] = temp;
    }
}
*/

// Reversal Algorithm
// Time Complexity => O(n), Space Complexity => O(1)
void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();
    d %= n;

    reverse(arr.begin(), arr.begin() + d); // O(n)
    reverse(arr.begin() + d, arr.end());   // O(n)
    reverse(arr.begin(), arr.end());       // O(n)
}

int main()
{

    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int d = 3;

    rotateArr(arr, d);

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}