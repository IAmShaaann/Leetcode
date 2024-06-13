class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int current = prices[i];
            if (current < buy)
                buy = current;
            else
            {
                int current_pro = current - buy;
                buy = current;
                profit += current_pro;
            }
        }
        return profit;
    }
};