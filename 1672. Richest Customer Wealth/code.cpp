class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = 0;
        for (vector<int> account : accounts)
        {
            int currentMoneyInAccount = 0;
            for (int money : account)
            {
                currentMoneyInAccount += money;
            }
            maxWealth = max(currentMoneyInAccount, maxWealth);
            currentMoneyInAccount = 0;
        }
        return maxWealth;
    }
};