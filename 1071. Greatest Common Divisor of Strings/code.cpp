#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool isDivisible(string s, string t)
{
    std::string smaller = s.size() > t.size() ? t : s;
    std::string newString = smaller + smaller;
    return s.find(smaller) != std::string::npos ? true : false;
}

string solution(string s, string t)
{
    return (s + t != t + s) ? "" : t.substr(0, gcd(s.size(), t.size()));
}

int main()
{
    string s = "ABABAB", t = "AC";
    cout << solution(s, t);
    return 0;
}