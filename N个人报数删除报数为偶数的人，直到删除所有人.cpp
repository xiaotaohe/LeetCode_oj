#include<iostream>
using namespace std;
struct Node
{
	int _data;
	Node* _next;
	Node(int data)
		:_data(data)
		, _next(nullptr)
	{}
};

int main()
{
	int n = 0;
	cin >> n;
	if (n == 0)
		return 0;
	Node* root = new Node(1);
	Node* cur = root;
	//构造循环链表
	for (int i = 2; i <= n; i++)
	{
		Node* tmp = new Node(i);
		cur->_next = tmp;
		cur = cur->_next;
	}
	cur->_next = root;
	//从为不开始每次走两步找到要删除的节点，删除该节点并输出data，
	//cur从pre开始继续走,直到cur->next == cur表示只剩一个了，然后输出
	while (cur->_next != cur)
	{
		Node* pre = nullptr;
		for (int i = 0; i < 2; i++)
		{
			pre = cur;
			cur = cur->_next;
		}
		cout << cur->_data<<" ";
		pre->_next = cur->_next;
		cur = pre;
	}
	cout << cur->_data<<endl;
	return 0;
}