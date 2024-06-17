#include <vector>
#include <iostream>
using namespace std;
int solution(vector<int> arr, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return arr[0];
    if (dp[n] != -1)
        return dp[n];

    int include = solution(arr, n - 2, dp) + arr[n];
    int exclude = solution(arr, n - 1, dp) + 0;
    int value = max(include, exclude);
    dp[n] = value;
    return value;
}
int memoization(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(nums.size() + 1, -1);
    int res = solution(nums, n - 1, dp);
    return res;
}

int tabulation(vector<int> &nums)
{
    // Write your code here.
    vector<int> dp(nums.size() + 1, -1);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[nums.size() - 1];
}