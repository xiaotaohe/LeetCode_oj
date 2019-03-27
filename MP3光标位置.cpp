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
    //将歌单处理为一个循环链表
    for(int i = 2;i<=num;i++)
    {
        pNode temp = new Node(i);
        cur->next = temp;
        temp->pre = cur;
        cur = cur->next;
    }
    head->pre = cur;
    cur->next = head;
    //页面歌曲的数目
    int page_num = 4;
    cur = head;
    char ch = 0;
    //歌曲跳转的过程
    while(cin>>ch)
    {
        if(ch == 'U')
            cur = cur->pre;
        if(ch == 'D')
            cur = cur->next;
        else
            continue;
    }
    //打印一页歌单
    //打印的歌曲不能超过歌单的总数，及总数小于一页的量时
    int index = cur->data;//当前歌曲位置
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