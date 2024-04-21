#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> arr)
{
    int max_alt = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
        arr[i] = arr[i - 1] + arr[i];

    for (auto it : arr)
        max_alt = max(max_alt, it);

    return max_alt < 0 ? 0 : max_alt;
}

int main()
{
    int arr[] = {-5, 1, 5, 0, -7};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
}