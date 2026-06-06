#include <iostream>
#include <vector>
using namespace std;

int secondLargest(vector<int> &arr)
{
    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }

        if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }

    // cout << secondLargest << endl;

    return secondLargest;
}

int main()
{
    vector<int> arr = {5, 5, 5};
    secondLargest(arr);

    return 0;
}