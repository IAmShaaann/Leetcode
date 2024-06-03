class Solution
{
public:
    int WithoutExtraSpace(vector<int> &arr)
    {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

class Solution
{
public:
    int WithExtraSpace(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end())
            {
                cnt += map[nums[i]];
            }
            map[nums[i]]++;
        }
        return cnt;
    }
};