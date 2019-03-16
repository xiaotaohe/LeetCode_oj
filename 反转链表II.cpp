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
    ListNode* reverse(ListNode* head,ListNode*& last,int num)
    {
        ListNode* ret = NULL;
        ListNode* tmp = NULL;
        while(num--&&head)
        {
            tmp = head;
            head = head->next;
            last = head;
            tmp->next = ret;
            ret = tmp;
        }
        return ret;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr)
            return head;
        ListNode* cur = head;//��������
        ListNode* ret = head;//��¼�µ�ͷ���
        ListNode* first = NULL;//��һ�ν�β
        ListNode* last = NULL;//�����ο�ͷ
        int countM = m;
        while(cur)
        {
            if(countM == 1)
            {
                if(cur == head)
                {
                    ret=reverse(cur,last,n-m+1);
                    cur->next = last;
                }
                else
                {
                    first->next=reverse(cur,last,n-m+1);
                    cur->next = last;
                }
            }
            countM--;
            first = cur;
            cur = cur->next;
        }
        return ret;
    }
};