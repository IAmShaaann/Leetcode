#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &arr, int k)
    {
        int size = arr.size();
        k %= size;
        reverse(arr.begin(), arr.begin() + (size - k));

        reverse(arr.begin() + (size - k), arr.end());

        reverse(arr.begin(), arr.end());
    }
};