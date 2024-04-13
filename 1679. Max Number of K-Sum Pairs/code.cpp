#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int optimal(vector<int> arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    int cnt = 0;
    sort(arr.begin(), arr.end());
    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cnt++;
            low++;
            high--;
        }
        else if (arr[low] + arr[high] < k)
        {
            low++;
        }
        else if (arr[low] + arr[high] > k)
        {
            high--;
        }
    }
    return cnt;
}
int solution(vector<int> arr, int k)
{
    unordered_map<int, int> map;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int complement = k - arr[i];
        if (map.find(complement) != map.end() and map[complement] > 0)
        {
            map[complement]--;
            cnt++;
        }
        else
        {
            map[arr[i]]++;
        }
    }
    return cnt;
}
int main()
{
    int arr[] = {3, 1, 3, 4, 3};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec, 6);
    return -1;
}