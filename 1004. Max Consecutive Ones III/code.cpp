#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> arr, int k)
{
    int start = 0, end = 0;
    int zeros = 0;
    int max_length = INT_MIN;
    while (end < arr.size())
    {
        if (arr[end] == 1)
            end++;
        else if (arr[end] == 0)
        {
            zeros++;
            if (zeros <= k)
            {
                end++;
            }
            else
            {
                while (zeros > k)
                {
                    if (arr[start] == 0)
                    {
                        zeros--;
                    }
                    start++;
                }
                end++;
            }
        }
        if (zeros <= k)
            max_length = max(max_length, end - start);
    }
    return max_length == INT_MIN ? 0 : max_length;
}
int main()
{
    int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec, k);
    return -1;
}