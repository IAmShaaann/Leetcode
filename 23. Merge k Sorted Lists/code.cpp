/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *brute_force(vector<ListNode *> &lists)
    {
        vector<int> res;
        for (auto list : lists)
        {
            ListNode *current = list;
            while (current != nullptr)
            {
                res.push_back(current->val);
                current = current->next;
            }
        }
        sort(res.begin(), res.end());
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        for (int i = 0; i < res.size(); i++)
        {
            tail->next = new ListNode(res[i]);
            tail = tail->next;
        }
        return head->next;
    }

    ListNode *better_than_brute_force(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;

        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            head = merge(head, lists[i]); // use merge function from 21. Merge Two Sorted Lists
        }
        return head;
    }

    ListNode *optimal(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> heap;
        for (ListNode *head : lists)
        {
            if (head)
                heap.push({head->val, head});
        }

        ListNode *currentHead = new ListNode(-1);
        ListNode *current = currentHead;

        while (!heap.empty())
        {
            ListNode *minimum = heap.top().second;
            heap.pop();
            if (minimum->next)
                heap.push({minimum->next->val, minimum->next});

            current->next = minimum;
            current = current->next;
        }
        return currentHead->next;
    }
};
