class Solution
{
public:
    int binary_search(vector<int> arr, int target, bool find_first_index)
    {
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                if (find_first_index)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return ans;
    }
    vector<int> optimal(vector<int> &nums, int target)
    {
        int first = binary_search(nums, target, true);
        int last = binary_search(nums, target, false);
        return {first, last};
    }
};

class Solution
{
public:
    vector<int> brute_force(vector<int> &nums, int target)
    {
        int first = -1;
        int last = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                first = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                last = i;
                break;
            }
        }
        return {first, last};
    }
};