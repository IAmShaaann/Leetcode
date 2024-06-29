#include <iostream>
#include <string>
#include <stack>
using namespace std;
string solutionTypeOne(string s) // time complexity - O(N / 2)
{
    string res = "";
    int low = 0;
    int high = s.size() - 1;
    while (low <= high)
    {
        swap(s[low], s[high]);
        low++;
        high--;
    }
    return s;
}

void solutionTypeTwo(string s)
{
    int last = 0;
    stack<string> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            string substr = s.substr(last, i - last);
            st.push(substr);
            last = i + 1;
        }
    }
    if (last < s.size())
    {
        string substr = s.substr(last, s.size() - last);
        st.push(substr);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    // string s = "Hello World How are you?"; // ?ouy era woH dlrow olleh
    string s = "Hello World How are you?"; // ?you are how world hello
    solutionTypeTwo(s);
}

// string solution(string s) // time complexity - O(N)
// {
//     string res = "";
//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         res += s[i];
//     }
//     return res;
// }