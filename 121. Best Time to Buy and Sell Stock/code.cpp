#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;
        int buy = prices[0];
        int profit = -1;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy)
                buy = prices[i];
            profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};