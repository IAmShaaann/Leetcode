class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left = 0, right = n, top = 0, bottom = n;
        int cnt = 1;
        while (left < right && top < bottom)
        {
            for (int i = left; i < right; i++)
            {
                ans[top][i] = cnt;
                cnt++;
            }
            top++;
            for (int i = top; i < bottom; i++)
            {
                ans[i][right - 1] = cnt;
                cnt++;
            }
            right--;

            if (!(left < right && top < bottom))
                break;

            for (int i = right - 1; i >= left; i--)
            {
                ans[bottom - 1][i] = cnt;
                cnt++;
            }
            bottom--;
            for (int i = bottom - 1; i >= top; i--)
            {
                ans[i][left] = cnt;
                cnt++;
            }
            left++;
        }
        return ans;
    }
};