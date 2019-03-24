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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
            if(fast == slow)
                break;
        }
        if(fast == nullptr)
            return nullptr;
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};