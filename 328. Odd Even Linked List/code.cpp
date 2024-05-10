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
    ListNode *brute_force(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> odds;
        vector<int> evens;
        ListNode *current = head;
        for (int i = 0; current != nullptr; ++i)
        {
            if (i % 2 == 0)
            {
                // Even index, push to evens
                evens.push_back(current->val);
            }
            else
            {
                // Odd index, push to odds
                odds.push_back(current->val);
            }
            current = current->next;
        }

        ListNode *start = new ListNode(evens[0]);
        ListNode *firstOfStart = start;

        for (int i = 1; i < evens.size(); i++)
        {
            ListNode *new_node = new ListNode(evens[i]);
            start->next = new_node;
            start = new_node;
        }

        for (int i = 0; i < odds.size(); i++)
        {
            ListNode *new_node = new ListNode(odds[i]);
            start->next = new_node;
            start = new_node;
        }
        return firstOfStart;
    }

    ListNode *optimal(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        ListNode *odd = oddHead;   // last index of odds
        ListNode *even = evenHead; // first index of evens

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return oddHead;
    }
};
