class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
        {
            if(l1)
                return l1;
            if(l2)
                return l2;
        }
        //找出cur1,cur2中较长的，默认cur1长
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* ret = new ListNode(0);
        ListNode* head = ret;
        int flag = 0;//进位标志
        while(cur1&&cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        if(cur1 == NULL)
        {
            cur1 = l2;
            cur2 = l1;
        }
        else
        {
            cur1 = l1;
            cur2 = l2;
        }
        //两数相加的逻辑
        while(cur2)
        {
           if((cur1->val+cur2->val+flag)>9)
           {
               ret->next = new ListNode(cur1->val+cur2->val+flag-10);
               flag = 1;
           }
            else
            {
                ret->next = new ListNode(cur1->val+cur2->val+flag);
                flag = 0;
            }
            ret = ret->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while(cur1)
        {
             if((cur1->val+flag)>9)
           {
               ret->next = new ListNode(cur1->val+flag-10);
               flag = 1;
           }
            else
            {
                ret->next = new ListNode(cur1->val+flag);
                flag = 0;
            }
            ret = ret->next;
            cur1 = cur1->next;
        }
        if(flag == 1)
            ret->next = new ListNode(1);
        head = head->next;
        return head;
    }
};
