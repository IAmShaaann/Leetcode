#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> solution(vector<int> &num, int k)
{
    int carry = 0;
    vector<int> result;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        int sum = num[i] + k % 10 + carry;
        k /= 10;
        carry = sum / 10;
        result.push_back(sum % 10);
    }

    while (k > 0)
    {
        int sum = k % 10 + carry;
        k /= 10;
        carry = sum / 10;
        result.push_back(sum % 10);
    }

    if (carry > 0)
        result.push_back(carry);
    reverse(result.begin(), result.end());

    return result;
}
int main()
{
    int arr[] = {1, 2, 0, 0};
    int k = 34;
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    solution(vec, k);
    return -1;
}