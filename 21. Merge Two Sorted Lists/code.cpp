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
    ListNode *brute_force(ListNode *list1, ListNode *list2)
    {
        vector<int> res;
        ListNode *temp = list1;
        while (temp != nullptr)
        {
            res.push_back(temp->val);
            temp = temp->next;
        }
        temp = list2;
        while (temp != nullptr)
        {
            res.push_back(temp->val);
            temp = temp->next;
        }

        if (res.size() == 0)
            return nullptr;

        sort(res.begin(), res.end());
        ListNode *current = new ListNode(res[0]);
        ListNode *currentHead = current;
        for (int i = 1; i < res.size(); i++)
        {
            ListNode *new_node = new ListNode(res[i]);
            current->next = new_node;
            current = current->next;
        }
        return currentHead;
    }

    ListNode *optimal(ListNode *list1, ListNode *list2)
    {
        ListNode currentHead(0);
        ListNode *current = &currentHead;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr)
            current->next = list1;
        else
            current->next = list2;

        return currentHead.next;
    }
};