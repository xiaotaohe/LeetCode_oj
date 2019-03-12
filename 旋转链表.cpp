/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<stdlib.h>
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* tail = head;
        ListNode* cur = head;
        int count = 0;
        while(cur)
        {
            tail = cur;
            count++;
            cur = cur->next;
        }
        tail->next = head;
        int step = k%count;
        int row = count-step;
        while(row--)
        {
            tail = tail->next;
        }
        cur = tail->next;
        tail->next = NULL;
        return cur;
    }
};