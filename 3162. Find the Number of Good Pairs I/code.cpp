class Solution
{
public:
    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int pairCount = 0;
        for (int i = 0; i < nums2.size(); i++)
        {
            nums2[i] = nums2[i] * k;
        }

        for (int value : nums1)
        {
            for (int it : nums2)
            {
                int remainder = value % it;
                if (remainder == 0)
                    pairCount++;
            }
        }
        return pairCount;
    }
};