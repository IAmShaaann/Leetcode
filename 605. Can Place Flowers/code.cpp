#include <iostream>
#include <vector>
using namespace std;
bool solution(vector<int> arr, int n)
{
    int cnt = 0;
    int size = arr.size();
    if (arr.size() == 0 or n == 0)
        return true;
    if (size == 1)
    {
        return arr[0] == 0 && n <= 1;
    }

    if (size == 2)
    {
        return (arr[0] == 0 && arr[1] == 0 && n <= 1) || n == 0;
    }

    if (arr[0] == 0 and arr[1] == 0)
    {
        cnt++;
        arr[0] = 1;
    }

    if (arr[size - 1] == 0 and arr[size - 2] == 0)
    {
        cnt++;
        arr[size - 1] = 1;
    }

    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i - 1] == 0 and arr[i + 1] == 0 and arr[i] != 1)
        {
            cnt++;
            arr[i] = 1;
        }
    }

    return cnt == n ? true : false;
}
