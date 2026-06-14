// One Traversal Solution - O(n) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{

    int minSoFar = prices[0], res = 0;

    for (int i = 1; i < prices.size(); i++)
    {

        // Update the minimum value seen so far
        minSoFar = min(minSoFar, prices[i]);

        // Update result if we get more profit
        res = max(res, prices[i] - minSoFar);
    }
    return res;
}

int main()
{
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}