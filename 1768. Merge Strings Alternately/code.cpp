#include <iostream>
#include <string>
using namespace std;
string solution(string s1, string s2)
{
    string s3;
    int i = 0, j = 0;
    while (i < s1.size() and j < s2.size())
    {
        s3.push_back(s1[i]);
        s3.push_back(s2[i]);
        i++;
        j++;
    }
    while (i < s1.size())
    {
        s3.push_back(s1[i]);
        i++;
    }
    while (j < s2.size())
    {
        s3.push_back(s2[j]);
        j++;
    }
    return s3;
}
int main()
{
    string word1 = "abc", word2 = "pqrs";
    cout << solution(word1, word2);
}