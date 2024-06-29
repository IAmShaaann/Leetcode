#include <iostream>
#include <vector>
using namespace std;

vector<int> array_union(vector<int> a, vector<int> b, int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> res;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            res.push_back(a[i++]);
        }
        else if (a[i] > b[j])
        {
            res.push_back(b[j++]);
        }
        else
        {
            res.push_back(a[i++]);
            j++;
        }
    }

    while (i < n)
    {
        res.push_back(a[i++]);
    }
    while (j < m)
    {
        res.push_back(b[j++]);
    }
    return res;
}

vector<int> intersection(vector<int> a, vector<int> b, int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> res;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else
        {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> vec1;
    vector<int> vec2;

    for (int i = 0; i < n; i++)
        vec1.push_back(arr1[i]);
    for (int i = 0; i < m; i++)
        vec2.push_back(arr2[i]);

    vector<int> res = intersection(vec1, vec2, n, m);
    for (auto it : res)
        cout << it << " ";
    return 0;
}