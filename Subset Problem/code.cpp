#include <iostream>
#include <vector>
using namespace std;
void solution(string s, int index, string current, vector<string> result)
{
    int N = s.length();
    if (N == index)
    {
        result.push_back(current);
        cout << current << " ";
        return;
    }
    solution(s, index + 1, current, result);
    solution(s, index + 1, current + s[index], result);
}

int main()
{
    string s = "abc";
    vector<string> result;
    int index = 0; // starting point
    string current = "";
    solution(s, index, current, result);

    return 0;
}