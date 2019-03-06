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
    //分段翻转，返回翻转之后的头部
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
        ListNode* cur = head;//遍历
        ListNode* pre = head;//翻转之后的头即就是尾
        ListNode* ret = head;//获取翻转之后的头
        ListNode* tail = head;//记录翻转之后的尾
        ListNode* last = NULL;//记录不够分段翻转部分的头结点
        bool ishead = false;//标记是否获取了新链表的头节点
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