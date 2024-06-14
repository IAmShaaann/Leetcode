#include <iostream>
#include <vector>
using namespace std;

int solution(int stairs, int current)
{
    if (stairs == current)
        return 1;
    if (current > stairs)
        return 0;

    int cnt = solution(stairs, current + 1) + solution(stairs, current + 2);
    return cnt;
}
int countDistinctWays(int nStairs)
{
    return solution(nStairs, 1);
}

int main()
{
    int result = countDistinctWays(4);
    cout << result;
    return 0;
}