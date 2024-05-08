class Solution
{
public:
    vector<vector<int>> solution(vector<int> arr1, vector<int> arr2)
    {
        unordered_set<int> first, second;
        vector<int> vec1, vec2;

        for (int i = 0; i < arr1.size(); i++)
            first.insert(arr1[i]);

        for (int i = 0; i < arr2.size(); i++)
            second.insert(arr2[i]);

        for (auto it : first)
        {
            if (second.find(it) == second.end()) // value not found.
                vec1.push_back(it);
        }

        for (auto it : second)
        {
            if (first.find(it) == first.end()) // value not found.
                vec2.push_back(it);
        }

        return {vec1, vec2};
    }
};
