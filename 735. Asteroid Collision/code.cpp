#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
    stack<int> st;
    vector<int> vec;
    for (auto astroid : arr)
    {
        if (st.empty() || astroid > 0)
            st.push(astroid);
        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < -astroid)
            {
                st.pop();
            }
            if (st.top() == -astroid)
            {
                st.pop();
            }
            else if (st.empty() || st.top() < 0)
            {
                st.push(astroid);
            }
        }
    }
    while (!st.empty())
    {
        vec.push_back(st.top());
        st.pop();
    }
    return vec;
}
int main()
{
    int arr[] = {10, 2, -5};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    solution(vec);
}