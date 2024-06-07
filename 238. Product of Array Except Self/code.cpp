#include <iostream>
#include <vector>
using namespace std;
/*

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int size = arr.size();
        vector<int> res;
        for(int i =0;i<size;i++){
            int product = 1;
            for(int j = 0; j<size;j++){
                if(i == j) continue;
                product*= arr[j];
            }
            res.push_back(product);

        }
        return res;
    }
};
*/

vector<int> solution(vector<int> arr)
{
    vector<int> result(arr.size(), 0);
    int zeros = 0;
    int product = 1;

    for (auto it : arr)
    {
        if (it == 0)
            zeros++;
        else
            product *= it;
    }

    if (zeros == 1)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                result[i] = product;
                break;
            }
        }
    }
    else if (zeros > 1)
    {
        return result;
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            result[i] = product / arr[i];
        }
    }
    return result;
}

int main()
{
    int arr[] = {-1, 1, 0, -3, 3};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    solution(vec);
}