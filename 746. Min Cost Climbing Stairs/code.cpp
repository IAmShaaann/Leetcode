#include <vector>
#include <iostream>
using namespace std;

class Recursive
{
public:
    int brute_force(int n, vector<int> cost, vector<int> dp)
    {
        if (n <= 1)
            return cost[n]; // BASE CASE
        if (dp[n] != -1)
            return dp[n];
        dp[n] = min(brute_force(n - 1, cost, dp), brute_force(n - 2, cost, dp)) + cost[n]; // Minimum cost to react 0 || 1 from n-1 or n-2 including the cost of current stair.
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size(); // number of stairs;
        vector<int> dp(n + 1, -1);
        int res = min(brute_force(n - 1, cost, dp), brute_force(n - 2, cost, dp));
        return res;
    }
};

class Memoization
{
public:
    int recursive_with_dp(vector<int> cost, int n, vector<int> dp) // Memoization
    {
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];

        if (dp[n] != -1)
            return dp[n];

        dp[n] = cost[n] + min(recursive_with_dp(cost, n - 1, dp), recursive_with_dp(cost, n - 2, dp));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int result = min(recursive_with_dp(cost, n - 1, dp), recursive_with_dp(cost, n - 2, dp));
        return result;
    }
};

class TabulationWithExtraSpace
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

class TabulationWithoutExtraSpace
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int last = cost[1];
        int second_last = cost[0];
        for (int i = 2; i < cost.size(); i++)
        {
            int current = cost[i] + min(last, second_last);
            second_last = last;
            last = current;
        }
        return min(second_last, last);
    }
};