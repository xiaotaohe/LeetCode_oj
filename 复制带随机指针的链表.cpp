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
        //在复杂链表的每个节点后面跟一个自己
        while(h1)
        {.......
            h1->next = new RandomListNode(h1->label);
            h1 ->next->next = next;
            h1 = next;
            if(h1)
                next = h1->next;
        }
        //将random复制好
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
        //现在开始拆
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