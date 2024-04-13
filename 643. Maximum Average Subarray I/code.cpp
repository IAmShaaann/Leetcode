#include <iostream>
#include <vector>
using namespace std;
double solution(vector<int> arr, int k)
{
    double sum = 0;
    double maxAverage = std::numeric_limits<double>::min();

    // Calculate the sum of the first 'k' elements and initialize 'minAverage'
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    maxAverage = sum / k;

    // Use a sliding window approach for subsequent subarrays of length 'k'
    for (int i = k; i < arr.size(); i++)
    {
        // Update the sum by subtracting the element that goes out of the window and adding the element that comes into the window
        sum = sum - arr[i - k] + arr[i];

        // Calculate the average for the current window and update 'minAverage' if necessary
        double currentAverage = sum / k;
        if (currentAverage > maxAverage)
        {
            maxAverage = currentAverage;
        }
    }
    return maxAverage;
}
int main()
{
    int arr[] = {1, 12, -5, -6, 50, 3};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec, 4);
    return -1;
}