#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void insert(stack<int> &res, int value)
{
    if (res.size() == 0 || res.top() < value)
    {
        res.push(value);
        return;
    }
    int top = res.top();
    res.pop();
    insert(res, value);
    res.push(top);
}
void sort(stack<int> st, stack<int> &res)
{
    if (st.size() == 1)
    {
        res.push(st.top());
        return;
    }
    int top = st.top();
    st.pop();
    sort(st, res);
    insert(res, top);
}
int main()
{

    int arr[] = {4, 2, 5, 1, 6, 7};
    stack<int> st;
    stack<int> res;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        st.push(arr[i]);
    }

    sort(st, res);
    while (!res.empty())
    {
        int top = res.top();
        cout << top << " "; // Print the top element of the stack
        res.pop();          // Pop the element from the stack
    }
    return 0;
}