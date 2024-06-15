#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> loots(nums.size(), 0);
        loots[0] = nums[0];
        loots[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            loots[i] = max(loots[i - 2] + nums[i], loots[i - 1]);
        }
        return loots[loots.size() - 1];
    }
};