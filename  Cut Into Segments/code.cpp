#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;
int solution(int n, int x, int y, int z, vector<int> &dp)
{
    if (n < 0)
        return INT_MIN;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int with_x = solution(n - x, x, y, z, dp) + 1;
    int with_y = solution(n - y, x, y, z, dp) + 1;
    int with_z = solution(n - z, x, y, z, dp) + 1;
    dp[n] = max(with_x, max(with_y, with_z));
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    int answer = solution(n, x, y, z, dp);
    if (answer < 0)
        return 0;
    return answer;
}