#include <iostream>
#include <vector>
using namespace std;
bool increasingTriplet(vector<int> arr)
{
    int secondSmallest = INT_MAX;
    int smallest = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= smallest)
            smallest = arr[i];
        else if (arr[i] < secondSmallest)
            secondSmallest = arr[i];
        else if (arr[i] > smallest and arr[i] > secondSmallest)
            return true;
    }
    return false;
}