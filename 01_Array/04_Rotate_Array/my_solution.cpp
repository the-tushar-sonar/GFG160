#include <bits/stdc++.h>
using namespace std;

void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();
    vector<int> temp(arr.begin(), arr.begin() + d);

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    copy(temp.begin(), temp.end(), arr.begin() + (n - d));
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;

    rotateArr(arr, d);

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}