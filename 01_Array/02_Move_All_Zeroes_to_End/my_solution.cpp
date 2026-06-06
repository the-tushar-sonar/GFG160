#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Optimal
/*
void pushZerosToEnd(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        cout << "iteration: " << j - 1 << endl;
        if (arr[j] == 0)
        {
            arr[i] = arr[j];
            cout << "i: " << arr[i] << endl;
            cout << "j: " << arr[j] << endl;
        }

        else if (arr[i] == 0 && arr[j] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
*/

// Brute Force
void pushZerosToEnd(vector<int> &arr)
{
    int n = arr.size();
    set<int> set;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            set.insert(arr[i]);
    }

    vector<int> newArr(n, 0);
    copy(set.begin(), set.end(), newArr.begin());
    for (int x : newArr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> arr = {1, 2, 0, 5, 0};

    pushZerosToEnd(arr);


    return 0;
}