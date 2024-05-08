#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool solution(string s1, string s2)
{
    unordered_map<char, int> first;
    unordered_map<char, int> second;
    vector<int> vec1, vec2;

    for (auto it : s1)
        first[it]++;

    for (auto it : s2)
    {
        if (first.find(it) == first.end())
            return false;
        second[it]++;
    }

    for (auto it : first)
        vec1.push_back(it.second);
    for (auto it : second)
        vec2.push_back(it.second);
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    return vec1 == vec2;
}
int main()
{
    string s1 = "cabbba", s2 = "abbccc2";
    cout << solution(s1, s2);
    return -1;
}