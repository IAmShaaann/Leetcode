#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int mid = 0;
        int start = 0;
        int end = arr.size() - 1;
        while (mid <= end)
        {
            if (arr[mid] == 0)
            {
                swap(arr[start], arr[mid]);
                start++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else if (arr[mid] == 2)
            {
                swap(arr[mid], arr[end]);
                end--;
            }
        }
    }
};