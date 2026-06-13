#include <bits/stdc++.h>
using namespace std;

// Brute Force => Time: O(n²)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int profit = 0;
    int maxprofit = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            profit = prices[j] - prices[i];
            maxprofit = max(maxprofit, profit);
        }
    }
    cout << "Max Profit : " << maxprofit << endl;
    return 0;
}

int main()
{
    // vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    // vector<int> prices = {7, 6, 4, 3, 1};
    vector<int> prices = {1, 3, 6, 9, 11};

    maxProfit(prices);

    return 0;
}