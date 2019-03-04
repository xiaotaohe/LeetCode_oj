class Solution {
public:
    ListNode* merge(ListNode*& list1,ListNode*& list2)
    {
        ListNode* temp = NULL;
        if(list1 == NULL&&list2 == NULL)
            return temp;
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
         if(list1->val>list2->val)
                {
                    temp = list2;
                    list2=list2->next;
                    
                }
                else
                {
                    temp = list1;
                    list1 = list1->next;
                }
                ListNode* temp1 = temp;
                while(list1&&list2)
                {
                    if(list1->val>list2->val)
                    {
                        temp->next = list2;
                        temp = temp->next;
                        list2 = list2->next;
                    }
                    else
                    {
                        temp->next = list1;
                        temp = temp->next;
                        list1 = list1->next;
                    }
                        
                }
                while(list1)
                {
                    temp->next = list1;
                    list1 = list1->next;
                    temp = temp->next;
                }
                while(list2)
                {
                    temp->next = list2;
                    list2 = list2->next;
                    temp = temp->next;
                }
                temp->next = NULL;
        return temp1;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        ListNode* list1=NULL;
        ListNode* list2=NULL;
        ListNode* temp1 = NULL;
        if(lists.size() == 1)
        {
            list1=lists[0];
        }
        else
        {
            while(lists.size()>2)
            {
                list1 = lists[lists.size()-1];
                list2 = lists[lists.size()-2];
                lists.pop_back();
                lists.pop_back();
                temp1= merge(list1,list2);
                if(temp1)
                    lists.push_back(temp1);
            }
            //if(lists.size() == 2)
                list1 =  merge(lists[0],lists[1]);
            /*if(lists.size() == 1)
                list1 = lists[0];
            else
                list1 = NULL;*/
        }
        return list1;
    }
};