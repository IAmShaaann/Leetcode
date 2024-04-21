#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &arr)
    {
        int k = 1;
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
        return max_length == INT_MIN ? 0 : max_length - 1;
    }
};