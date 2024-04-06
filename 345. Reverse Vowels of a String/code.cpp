#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
bool isVowel(char s)
{
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
    {
        return true;
    }
    return false;
}

string solution(string s)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
    {

        if (isVowel(s[start]) and isVowel(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else if (isVowel(s[start]) and !isVowel(s[end]))
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return s;
}
int main()
{
    string s = "leetcode";
    cout << solution(s);
    return -1;
}