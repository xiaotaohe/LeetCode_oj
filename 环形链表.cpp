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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast&&fast->next)
                fast = fast->next;
            else
                return false;
            if(fast == slow)
                return true;
        }
        return false;
    }
};