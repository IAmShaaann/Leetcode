#include <string>
#include <iostream>
using namespace std;
string brute(string s)
{
    vector<char> res;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '*')
        {
            res.push_back(s[i]);
        }
        else
        {
            res.pop_back();
        }
    }
    string str = "";
    for (auto it : res)
        str += it;
    return str;
}
string solution(string s)
{
    string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
            str.pop_back();
        else
            str.push_back(s[i]);
    }
    return str;
}

int main()
{
    string s = "leet**cod*e";
    cout << solution(s);
    return -1;
}