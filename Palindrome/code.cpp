#include <iostream>
#include <string>
using namespace std;
bool solution(string s)
{
    int low = 0;
    int high = s.size() - 1;
    while (low < high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}
int main()
{
    string s = "abcdcba";
    cout << solution(s);

    return 0;
}