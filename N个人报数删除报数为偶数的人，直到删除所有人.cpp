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
	//����ѭ������
	for (int i = 2; i <= n; i++)
	{
		Node* tmp = new Node(i);
		cur->_next = tmp;
		cur = cur->_next;
	}
	cur->_next = root;
	//��Ϊ����ʼÿ���������ҵ�Ҫɾ���Ľڵ㣬ɾ���ýڵ㲢���data��
	//cur��pre��ʼ������,ֱ��cur->next == cur��ʾֻʣһ���ˣ�Ȼ�����
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