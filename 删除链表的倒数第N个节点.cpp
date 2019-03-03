class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        ListNode* f = head;
        ListNode* s = head;
        ListNode* cur = NULL;
        for(int i = 0;i<n&&f;i++)
            f = f->next;
        while(f)
        {
            cur = s;
            f=f->next;
            s=s->next;
        }
        if(cur == NULL)
            head = head->next;
        else
            cur->next = cur->next->next;
        return head;
    }
};