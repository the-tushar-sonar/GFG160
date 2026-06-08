#include <bits/stdc++.h>
using namespace std;

/*
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
*/

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

int main()
{

    vector<int> arr = {7, 3, 9, 1};
    int d = 9;

    rotateArr(arr, d);

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}