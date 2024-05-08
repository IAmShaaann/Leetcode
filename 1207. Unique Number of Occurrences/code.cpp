#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool solution(vector<int> arr)
{
    unordered_map<int, int> map;
    unordered_map<int, int> freq;
    for (auto it : arr)
        map[it]++;

    for (auto it : map)
    {
        freq[it.second]++;
    }

    for (auto it : freq)
    {
        if (it.second > 1)
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 2, 1, 1, 3};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
}