#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    reverseArray(arr);

    return 0;
}