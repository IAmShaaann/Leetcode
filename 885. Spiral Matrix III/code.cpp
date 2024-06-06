class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart)
    {
        vector<vector<int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Top
        vector<vector<int>> ans;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int row = rStart;
        int col = cStart;
        int direction_index = 0;
        int steps = 1;

        ans.push_back({row, col});
        visited[row][col] = true;

        while (ans.size() < rows * cols)
        {
            int direction_row = directions[direction_index % 4][0];
            int direction_col = directions[direction_index % 4][1];
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < steps; j++)
                {
                    row += direction_row;
                    col += direction_col;
                    if (row >= 0 && row < rows && col >= 0 && col < cols)
                    {
                        ans.push_back({row, col});
                        visited[row][col] = true;
                    }
                }
                direction_index = (direction_index + 1) % 4;
                swap(direction_row, direction_col);
            }
            steps++;
        }
        return ans;
    }
};