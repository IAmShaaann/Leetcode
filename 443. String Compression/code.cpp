#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int failed(vector<char> arr)
{
    if (arr.size() == 1)
        return 1;
    unordered_map<char, int> map;
    string s = "";
    for (int i = arr.size() - 1; i >= 0; i--)
        map[arr[i]]++;

    for (auto it : map)
    {
        if (it.second > 1)
            s += it.first + to_string(it.second);
        else
            s += it.first;
    }

    arr.resize(0, 0);
    for (int i = 0; i < s.size(); i++)
        arr.push_back(s[i]);

    return s.size();
}
int solution(vector<char> arr)
{
    if (arr.size() == 1)
        return arr.size();

    int charCnt = 1;
    int writeIndex = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i + 1 < arr.size() && arr[i] == arr[i + 1])
        {
            charCnt++;
        }
        else
        {
            // Write the character
            arr[writeIndex] = arr[i];
            writeIndex++;

            // Write the count if greater than 1
            if (charCnt > 1)
            {
                string countStr = to_string(charCnt);
                for (char c : countStr)
                {
                    arr[writeIndex] = c;
                    writeIndex++;
                }
                charCnt = 1;
            }
        }
    }

    // Trim the array to the new length
    arr.resize(writeIndex);
    return writeIndex;
}

int main()
{
    char arr[] = {
        'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);

    solution(vec);
    return -1;
}