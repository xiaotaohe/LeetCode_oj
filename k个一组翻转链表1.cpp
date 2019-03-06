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
    //�ֶη�ת�����ط�ת֮���ͷ��
    ListNode* reverse(ListNode* head, int k)
    {
        ListNode* ret = nullptr;
        while(k--)
        {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = ret;
            ret = tmp;
        }
        return ret;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        int count = k;
        ListNode* cur = head;//����
        ListNode* pre = head;//��ת֮���ͷ������β
        ListNode* ret = head;//��ȡ��ת֮���ͷ
        ListNode* tail = head;//��¼��ת֮���β
        ListNode* last = NULL;//��¼�����ֶη�ת���ֵ�ͷ���
        bool ishead = false;//����Ƿ��ȡ���������ͷ�ڵ�
        while(cur)
        {
            count--;
            if(last == NULL)
                last = cur;
            cur = cur->next;
            if(count == 0)
            {
                if(ishead == false)
                {
                    ret = reverse(pre,k);
                    pre->next = cur;
                    ishead = true;
                    tail = pre;
                }
                else
                {
                    tail->next = reverse(pre,k);
                    tail = pre;
                }
                pre = cur;
                last = NULL;
                count = k;
            }
        }
        if(ishead == false)
            return head;
        tail->next = last;
        return ret;
    }
};