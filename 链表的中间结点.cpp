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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast&&slow)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }
        return slow;
    }
};