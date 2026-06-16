#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    // for (int price : prices)
    // {
    //     cout << price << " ";
    // }
    // cout << endl;

    int n = prices.size();
    int profit = 0;
    int totalProfit = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit = prices[i] - prices[i - 1];
            // cout << profit << " ";
            totalProfit += profit;
        }
    }

    cout << "Total Profit: " << totalProfit << endl;

    return totalProfit;
}

int main()
{

    vector<int> arr1 = {1, 2, 3, 4, 5};
    maxProfit(arr1);

    vector<int> arr2 = {5, 4, 3, 2, 1};
    maxProfit(arr2);

    vector<int> arr3 = {1, 5, 3, 8}; 
    maxProfit(arr3);

    vector<int> arr4 = {7, 1, 5, 3, 6, 4}; 
    maxProfit(arr4);

    vector<int> arr5 = {1, 3, 2, 4, 3, 5}; 
    maxProfit(arr5);

    vector<int> arr6 = {5, 5, 5, 5};
    maxProfit(arr6);

    vector<int> arr7 = {10};
    maxProfit(arr7);

    vector<int> arr8 = {2, 8};
    maxProfit(arr8);

    vector<int> arr9 = {8, 2};
    maxProfit(arr9);

    vector<int> arr10 = {2, 4, 1, 5, 3, 6}; 
    maxProfit(arr10);

    vector<int> arr11 = {10, 1, 2, 3, 4, 8};
    maxProfit(arr11);

    vector<int> arr12 = {3, 2, 6, 5, 0, 3};
    maxProfit(arr12);

    vector<int> arr13 = {};
    maxProfit(arr13);

    return 0;
}