class Solution
{
public:
    int brute_force(vector<int> &nums, int target)
    {
        int pairCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] < target)
                    pairCount++;
            }
        }
        return pairCount;
    }
};

class Solution
{
public:
    int optimal(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int pairCount = 0;
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] < target)
            {
                pairCount += high - low;
                low++;
            }
            else if (nums[low] + nums[high] >= target)
            {
                high--;
            }
        }
        return pairCount;
    }
};