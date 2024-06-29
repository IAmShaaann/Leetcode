#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &arr, int value)
{
    if (arr.size() == 0 || value >= arr[arr.size() - 1])
    {
        arr.push_back(value);
        return;
    }
    int last = arr[arr.size() - 1];
    arr.pop_back();
    insert(arr, value);
    arr.push_back(last);
}

void sort(vector<int> arr, vector<int> &res)
{
    if (arr.size() == 1)
    {
        res.push_back(arr[0]);
        return;
    }
    int last = arr[arr.size() - 1];
    arr.pop_back();
    sort(arr, res);
    insert(res, last); // Use an iterative approach where you have to iterate through the array and place it on the correct position.
}
int main()
{
    int arr[] = {4, 2, 5, 1, 6, 7};
    vector<int> vec;
    vector<int> res;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    sort(vec, res);
    for (auto it : res)
        cout << it << " ";
    return 0;
}