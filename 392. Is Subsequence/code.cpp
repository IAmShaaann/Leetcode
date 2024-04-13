#include <iostream>
#include <string>
using namespace std;
bool solution(string s, string t)
{
    int start = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (s[start] == t[i])
        {
            start++;
        }
    }
    return start == s.size();
}
int main()
{
    string s = "axc";
    string t = "ahbgdc";
    cout << solution(s, t);
    return -1;
}