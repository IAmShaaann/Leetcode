#include <vector>
#include <iostream>
using namespace std;
int solution(int n)
{
    if (n == 0)
    {
        return n;
    }

    int res = solution(n - 1);
    cout << n << " ";

    return res;
}
int main()
{
    int n = 10;
    solution(n);
    return 0;
}