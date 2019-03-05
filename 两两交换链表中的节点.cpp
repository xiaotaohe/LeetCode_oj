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
    void swap(ListNode* pre,ListNode* l,ListNode* r)
    {
        ListNode* tmp = r->next;
        r->next = l;
        l->next = tmp;
        if(pre)
            pre->next = r;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* l = head;
        ListNode* r = head->next;
        ListNode* pre = NULL;
        head = head->next;
        swap(pre,l,r);
        pre = l;
        l = l->next;
        if(l == NULL)
            return head;
        r = l->next;
        while(1&&r)
        {
            swap(pre,l,r);
            pre = l;
            l = l->next;
            if(l == NULL)
                break;
            r = l->next;
        }
        return head;
    }
};