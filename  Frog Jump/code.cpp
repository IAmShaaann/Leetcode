#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int memoized(int n, vector<int> costs, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = memoized(n - 1, costs, dp) + abs(costs[n] - costs[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = memoized(n - 2, costs, dp) + abs(costs[n] - costs[n - 2]);

    dp[n] = min(left, right);
    return dp[n];
}

int tabulation(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

int without_extra_space(int n, vector<int> &heights)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return abs(heights[1] - heights[0]);
    int first = 0;
    int second = abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++)
    {
        int left = second + abs(heights[i] - heights[i - 1]);
        int right = first + abs(heights[i] - heights[i - 2]);
        int next = min(left, right);
        first = second;
        second = next;
    }
    return second;
}