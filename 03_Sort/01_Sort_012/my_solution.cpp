#include <bits/stdc++.h>
using namespace std;

void sort_012(vector<int> &arr)
{

    int lo = 0;
    int mid = 0;
    int hi = arr.size() - 1;

    while (mid <= hi)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[lo]);
            mid++;
            lo++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[hi]);
            hi--;
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2};

    sort_012(arr);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}