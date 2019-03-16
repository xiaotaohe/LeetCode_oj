/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return head;
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode* p1 = first;
        ListNode* p2 = second;
        while(head)
        {
            if(head->val<x)
            {
                first->next = new ListNode(head->val);
                first = first->next;
            }
            else
            {
                second->next = new ListNode(head->val);
                second = second->next;
            }
            head = head->next;
        }
        first->next = p2->next;
        return p1->next;
    }
};