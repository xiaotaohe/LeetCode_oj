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
    ListNode* reverse(ListNode* head)
    {
        ListNode* ret = nullptr;
        ListNode* tmp = nullptr;
        while(head)
        {
            tmp = head;
            head = head->next;
            tmp->next = ret;
            ret = tmp;
        }
        return ret;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* pre = nullptr;
        //�ҳ������ö̵�ȥ�ӳ���,Ĭ��cur1Ϊ�����г����Ǹ�
        while(cur1&&cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        if(cur1 == nullptr)
        {
            cur1 = l2;
            cur2 = l1;
            l1 = cur1;
            l2 = cur2;
        }
        else
        {
            cur1 = l1;
            cur2 = l2;
        }
        //flag��ʾ1��λ��0��ʾ����λ
        int flag = 0;
        while(cur2)
        {
            if(cur1->val+cur2->val+flag>9)
            {
                cur1->val = cur1->val+cur2->val+flag-10;
                flag = 1;
            }
            else
            {
                cur1->val = cur1->val+cur2->val+flag;
                flag = 0;
            }
            cur2 = cur2->next;
            pre = cur1;
            cur1 = cur1->next;
        }
        while(flag)
        {
            if(pre->next)
            {
                if(pre->next->val+flag>9)
                {
                    pre->next->val = pre->next->val+flag-10;
                    flag = 1;
                }
                else
                {
                     pre->next->val = pre->next->val+flag;
                    flag = 0;
                }
            }
            else
            {
                pre->next = new ListNode(flag);
                flag = 0;
            }
            pre = pre->next;
        }
        return reverse(l1);
    }
};