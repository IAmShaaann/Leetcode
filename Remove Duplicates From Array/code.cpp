#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void hashmap(vector<int> arr)
{
    // creating a freq array. However the freq array works better when we are trying to find duplicate chars rather than int.
    unordered_map<int, int> map; // Space Complexity O(N) | Time Complexity O(N)
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        if (map.find(arr[i]) == map.end())
        {
            res.push_back(arr[i]);
            map[arr[i]]++;
        }
    }
    for (auto it : res)
        cout << it << " ";
}

void sorting(vector<int> arr)
{
    sort(arr.begin(), arr.end()); // Time Complexity - O(nlogn) | Space Complexity - O(1)
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != arr[i + 1])
        {
            res.push_back(arr[i]);
        }
    }
    if (arr[arr.size() - 1] != res[res.size() - 1])
    {
        res.push_back(arr[arr.size() - 1]);
    }
    for (auto it : res)
        cout << it << " ";
}

int main()
{
    int arr[] = {2, 3, 4, 2, 4, 2, 4, 5, 5, 5, 3, 2, 2, 1, 999};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    hashmap(vec);
    cout << endl;
    sorting(vec);
    return 0;
}