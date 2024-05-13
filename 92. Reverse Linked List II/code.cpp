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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr || head->next == nullptr || left == right)
            return head;

        ListNode trailer(0);
        trailer.next = head;
        ListNode *previous = &trailer;

        for (int i = 1; i < left; i++)
        { // get to the correct start position.
            previous = previous->next;
        }

        ListNode *current = previous->next; // first value to be reversed.
        ListNode *next = nullptr;
        ListNode *sublist_head = current;

        for (int i = left; i < right; i++)
        {
            next = current->next;
            current->next = next->next;
            next->next = previous->next;
            previous->next = next;
        }
        return trailer.next;
    }
};