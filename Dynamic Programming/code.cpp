#include <iostream>
#include <vector>
using namespace std;
int iterative_with_tabulation(int n)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

int recursion_with_dynamic_programming(int n)
{
    vector<int> dp(n + 1, -1); // memoization.
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = recursion_with_dynamic_programming(n - 1) + recursion_with_dynamic_programming(n - 2); // recursive function calls and storing the values in the memoized map.
    return dp[n];
}

int best(int n)
{
    int second_last = 0;
    int last = 1;
    for (int i = 2; i <= n; i++)
    {
        int current = second_last + last;
        second_last = last;
        last = current;
    }

    return last;
}

int main()
{
    int n = recursion_with_dynamic_programming(12);
    cout << n;
    return 0;
}