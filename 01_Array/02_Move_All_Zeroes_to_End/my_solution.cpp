#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Optimal
void pushZerosToEnd(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        // cout << "iteration: " << j << endl;
        // cout << "Before :" << endl;
        // cout << "i: " << i << endl;
        // cout << "j: " << "at " << j << " is " << arr[j] << endl;
        if (arr[i] == 0 && arr[j] == 0)
        {
            continue;
        }
        else if (arr[j] == 0)
        {
            i = j;
        }
        else if (arr[i] == 0 && arr[j] != 0)
        {
            // cout << "swap: " << endl;
            swap(arr[i], arr[j]);
            i++;
        }

        // cout << "After :" << endl;
        // cout << "i: " << i << endl;
        // cout << "j: " << "at " << j << " is " << arr[j] << endl;
    }
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}
/*
 */

// Brute Force
/*
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
*/

int main()
{

    vector<int> arr = {0, 1, 2, 3};
    pushZerosToEnd(arr);
    vector<int> arr1 = {1, 2, 3, 0};
    pushZerosToEnd(arr1);
    vector<int> arr2 = {0, 0, 1, 2};
    pushZerosToEnd(arr2);
    vector<int> arr3 = {1, 0, 0, 2};
    pushZerosToEnd(arr3);
    vector<int> arr4 = {0, 0, 0};
    pushZerosToEnd(arr4);
    vector<int> arr5 = {1, 2, 3};
    pushZerosToEnd(arr5);
    vector<int> arr6 = {0, 1, 0, 2, 0, 3};
    pushZerosToEnd(arr6);

    return 0;
}