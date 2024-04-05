#include <iostream>
#include <vector>
using namespace std;
vector<bool> solution(vector<int> &candies, int extraCandies)
{
    int maxAvailableCandies = 0;
    vector<bool> result(candies.size(), false);
    for (auto it : candies)
    {
        maxAvailableCandies = max(it, maxAvailableCandies);
    }
    for (int i = 0; i < candies.size(); i++)
    {
        result[i] = (candies[i] + extraCandies >= maxAvailableCandies) ? true : false;
    }
    return result;
}
