class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int cnt = 0;
        map<vector<int>, int> = map;
        vector<int> vec(grid.size(), 0);

        for (int i = 0; i < grid.size(); i++) // map the frequent of each row in the grid
            map[grid[i]]++;

        for (int col = 0; col < grid[0].size(); col++)
        {
            for (int row = 0; row < grid.size(); row++) // create vector/array/string of each column, and check if the columns exists in the map.
                vec[row] = grid[row][col];

            if (map.find(vec) != map.end()) // if yes, increase cnt by the number of times the vector exists in the map.
                cnt += map[vec];
        }
        return cnt;
    }
};