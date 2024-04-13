#include <vector>
#include <iostream>
using namespace std;
int solution(vector<int> arr)
{
    int maxProduct = -1;
    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        int width = high - low;
        int height = min(arr[low], arr[high]);

        int currentProduct = width * height;
        maxProduct = max(currentProduct, maxProduct);

        if (arr[low] < arr[high])
            low++;
        else if (arr[low] > arr[high])
        {
            high--;
        }
        else
        {
            low++;
            high--;
        }
    }
    return maxProduct;
}
int main()
{
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
    return -1;
}