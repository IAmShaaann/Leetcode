class Solution
{
public:
    void rotate(vector<int> &arr, int k)
    {
        int size = arr.size();
        k %= size;
        reverse(arr.begin(), arr.begin() + (size - k));
        for (auto it : arr)
            cout << it << " ";
        reverse(arr.begin() + (size - k), arr.end());
        for (auto it : arr)
            cout << it << " ";
        reverse(arr.begin(), arr.end());
        for (auto it : arr)
            cout << it << " ";
    }
};