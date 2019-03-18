/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode* next = head->next;
         RandomListNode* h1 = head;
        //�ڸ��������ÿ���ڵ�����һ���Լ�
        while(h1)
        {.......
            h1->next = new RandomListNode(h1->label);
            h1 ->next->next = next;
            h1 = next;
            if(h1)
                next = h1->next;
        }
        //��random���ƺ�
        h1 = head;
        next = head->next;
        while(h1)
        {
            if(h1->random)
                next->random = h1->random->next;
            h1 = next->next;
            if(h1)
                next = h1->next;
        }
        //���ڿ�ʼ��
        h1 = head;
        RandomListNode* h2 = head->next;
        RandomListNode* h = h2;
        while(h2)
        {
            h1->next = h2->next;
            h1 = h1->next;
            if(h1)
                h2->next = h1->next;
            h2 = h2->next;
           
       } 
        return h;
    }
};