#include <bits/stdc++.h>
using namespace std;

// Brute Force
int inversionCount(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
                cout << arr[i] << "\t" << arr[j] << "\t" << count << endl;
            }
        }
    }

    cout << count << endl;
    return count;
}


int inversionCount(vector<int> &arr)
{}

    int main()
{
    // vector<int> arr = {2, 4, 1, 3, 5};
    // vector<int> arr = {2, 3, 4, 5, 6};
    // vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> arr = {5, 5, 5};
    inversionCount(arr);

    return 0;
}