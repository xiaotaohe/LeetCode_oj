#include<iostream>
using namespace std;
#include<stack>

struct Node
{
    Node(int _data)
        :data(_data)
        ,pre(nullptr)
        ,next(nullptr)
    {}
    int data;
    struct Node* next;
    struct Node* pre;
};

int main()
{
    typedef struct Node* pNode;
    pNode  head;
    pNode cur = nullptr;
    int num = 0;
    cin>>num;
    head = new Node(1);
    cur = head;
    //���赥����Ϊһ��ѭ������
    for(int i = 2;i<=num;i++)
    {
        pNode temp = new Node(i);
        cur->next = temp;
        temp->pre = cur;
        cur = cur->next;
    }
    head->pre = cur;
    cur->next = head;
    //ҳ���������Ŀ
    int page_num = 4;
    cur = head;
    char ch = 0;
    //������ת�Ĺ���
    while(cin>>ch)
    {
        if(ch == 'U')
            cur = cur->pre;
        if(ch == 'D')
            cur = cur->next;
        else
            continue;
    }
    //��ӡһҳ�赥
    //��ӡ�ĸ������ܳ����赥��������������С��һҳ����ʱ
    int index = cur->data;//��ǰ����λ��
    int count = 0;
    stack<int> s;
    while(page_num && count != num)
    {
        s.push(cur->data);
        cur = cur->pre;
        page_num--;
        count++;
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<index<<endl;
}