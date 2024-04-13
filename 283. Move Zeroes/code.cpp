#include <iostream>
using namespace std;
void solution(vector<int> &arr)
{
    int hasZeros = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            hasZeros = i;
            break;
        }
    }
    if (hasZeros == -1)
        return;

    for (int i = hasZeros + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[hasZeros]);
            hasZeros++;
        }
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void answer(vector<int> &arr) // if the motive is only to move zeros to the end.
{
    int start = 0;
    int end = arr.size() - 1;
    for (int i = 0; i < end; i++)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[end]);
            end--;
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    answer(vec);
    return -1;
}