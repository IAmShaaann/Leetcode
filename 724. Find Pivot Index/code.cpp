#include <iostream>
#include <vector>
using namespace std;
int calculate_sum(vector<int> arr, int index, bool check_left)
{
    int sum = 0;
    if (check_left)
    {
        for (int i = 0; i < index; i++)
            sum += arr[i];
    }
    else
    {
        for (int i = index + 1; i < arr.size(); i++)
            sum += arr[i];
    }
    return sum;
}
int unoptimised(vector<int> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        long long left = calculate_sum(arr, i, true);
        long long right = calculate_sum(arr, i, false);
        if (left == right)
            return i;
    }
    return -1;
}
int accumulate(vector<int> arr)
{
    int sum = 0;
    for (auto it : arr)
        sum += it;
    return sum;
}
int solution(vector<int> arr)
{
    int right_sum = accumulate(arr);
    int left_sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        right_sum -= arr[i];
        if (left_sum == right_sum)
            return i;
        left_sum += arr[i];
    }
    return -1;
}

int main()
{
    int arr[] = {2, 1, -1};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
}