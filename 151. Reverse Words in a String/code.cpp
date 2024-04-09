#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string trim(string s)
    {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        return s;
    }
    string reverseWords(string s)
    {
        stack<string> st;
        int lastValidIndex = 0;
        string reversedString = "";

        while (lastValidIndex < s.size())
        {
            while (lastValidIndex < s.size() and s[lastValidIndex] == ' ')
                lastValidIndex++;

            if (lastValidIndex == s.size())
                lastValidIndex++;

            string word = "";
            while (lastValidIndex < s.size() and s[lastValidIndex] != ' ')
            {
                word += s[lastValidIndex];
                lastValidIndex++;
            }
            st.push(word);
        }
        while (!st.empty())
        {
            reversedString += st.top() + ' ';
            st.pop();
        }
        if (!reversedString.empty())
        {
            reversedString.pop_back();
        }
        return trim(reversedString);
    }
};