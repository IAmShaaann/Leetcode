#include <iostream>
#include <stack>
using namespace std;

void removeMiddle(stack<int> &st, int size)
{
    if (st.empty() || size == 0)
    {
        if (!st.empty())
        {
            st.pop();
        }
        return;
    }
    int top = st.top();
    st.pop();
    removeMiddle(st, size - 1);

    if (size != 1)
    {
        st.push(top);
    }
}

int main()
{

    int arr[] = {4, 2, 5, 1, 0, 6, 7};
    stack<int> st;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        st.push(arr[i]);
    }

    int k = st.size() / 2 + 1;
    removeMiddle(st, k);

    while (!st.empty())
    {
        int top = st.top();
        cout << top << " "; // Print the top element of the stack
        st.pop();           // Pop the element from the stack
    }
    return 0;
}