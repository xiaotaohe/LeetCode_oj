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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr||head->next == nullptr)
         return head;
        ListNode* pre = head;
        ListNode* del = head;
        bool isdel = false;
        while(del)
        {
            if(del->next == nullptr)
                break;
            if(del->val == del->next->val)
            {
                isdel = true;
                while(del->next)
                {
                    if(del->val != del->next->val)
                        break;
                    del = del->next;
                }
                if(del->val == head->val)
                {
                    head = del->next;
                    del = pre;
                    while(del!=head)
                    {
                        ListNode* tmp = del;
                        del = del->next;
                        delete del;
                    }
                    pre = head;
                }
                else
                {
                    del = pre->next;
                    pre->next = del->next;
                    while(del != pre->next)
                    {
                        ListNode* tmp = del;
                        del = del->next;
                        delete del;
                    }
                }
            }
            if(isdel)
            {
                del = pre;
                isdel = false;
            }
            else
            {
                pre = del;
                del = del->next;
            }
        }
        return head;
    }
};