#include <iostream>
#include <vector>
using namespace std;

int largest(vector<int> arr) // time complexity - O(N) space complexity - O(1)
{
    int second_largest = -1;
    int largest = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
    }
    return second_largest;
}

int smallest(vector<int> arr) // time complexity - O(N) space complexity - O(1)
{
    int second_smallest = INT_MAX;
    int smallest = INT_MAX - 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
    }
    return second_smallest;
}

int solution(vector<int> arr, string operation)
{
    if (operation == "largest")
        return largest(arr);
    else
        return smallest(arr);
}

int main()
{
    int arr[] = {6, 2, 4, 5, 7, 8, 3, 1};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    int res = solution(vec, "smallest");
    cout << "Result: " << res;

    return 0;
}

// int brute_force (vector<int> arr) // time complexity - O(nlogn)
// {
//     sort(arr.begin(), arr.end());
//     return arr[arr.size() - 2];
// }