#include <vector>
#include <iostream>
using namespace std;
int recursive(vector<int> cost, int target)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;
    int minimum = INT_MAX;
    int value = INT_MAX;
    for (int i = 0; i < cost.size(); i++)
    {
        value = recursive(cost, target - cost[i]);
        if (value != INT_MAX)
            minimum = min(minimum, value + 1);
    }
    return minimum;
}

int memoization(vector<int> cost, int target, vector<int> dp)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;
    int mini = INT_MAX;
    if (dp[target] != -1)
        return dp[target];

    for (int i = 0; i < cost.size(); i++)
    {
        int value = memoization(cost, target - cost[i], dp);
        if (value != INT_MAX)
        {
            mini = min(mini, value + 1);
        }
    }
    dp[target] = mini;
    return mini;
}

int tabulation(vector<int> &cost, int amount) // amount = 17
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // BASECASE
    for (int i = 0; i <= amount; i++)
    { // check for every amount - (amount - 1), (amount - 2), (amount - 3) (amount - 17)
        for (int j = 0; j < cost.size(); j++)
        { // for every cost in the array - (amount - cost[0]) (amount - cost[1]) (amount - cost[n])
            if (i - cost[j] >= 0 && dp[i - cost[j]] != INT_MAX)
            {                                            // if the index is valid and the cost is not greater than INT_MAX
                dp[i] = min(dp[i], dp[i - cost[j]] + 1); // minimum of current dp index and dp[current_value - cost[j]] + 1, +1 for adding the number of coins.
            }
        }
    }

    if (dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}
