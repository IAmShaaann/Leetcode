class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> arr(n - 2, vector<int>(n - 2, 0));

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                int currentMax = -1;
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        currentMax = max(currentMax, grid[x][y]);
                    }
                }
                arr[i][j] = currentMax;
            }
        }
        return arr;
    }
};