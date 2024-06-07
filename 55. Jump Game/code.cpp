

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int final_position = nums.size() - 1;
        for (int start = final_position - 1; start >= 0; start--)
        {
            if (start + nums[start] >= final_position)
            {
                final_position = start;
            }
        }
        return final_position == 0;
    }
};