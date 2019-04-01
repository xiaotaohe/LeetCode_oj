#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<algorithm>

struct Node
{
	int row;
	int col;
	Node(int _row, int _col)
		:row(_row)
		, col(_col)
	{}
};

typedef Node Node;
void get_path(vector<vector<int>>& v)
{
	int col = 0, row = 0;
	v[row][col] = 2;
	stack<Node> s;
	s.push(Node(row, col));
	while ((row != v.size() - 1 || col != v[0].size() - 1) && !s.empty())
	{
		//向下走
		if (0 <= row + 1 && row + 1<v.size() && (v[row + 1][col] == 0))
		{
			v[row + 1][col] = v[row][col] + 1;
			row++;
			s.push(Node(row, col));
		}
		//向右走
		else if (0 <= col + 1 && col + 1 < v[0].size() && (v[row][col + 1] == 0))
		{
			v[row][col + 1] = v[row][col] + 1;
			col++;
			s.push(Node(row, col));
		}
		//向上走
		else if (row - 1 >= 0 && row - 1 < v.size() && (v[row - 1][col] == 0))
		{
			v[row - 1][col] = v[row][col];
			row--;
			s.push(Node(row, col));
		}
		//向左走
		else if (0 <= col - 1 && col - 1 < v[0].size() && (v[row][col - 1] == 0))
		{
			v[row][col -1] = v[row][col] + 1;
			col--;
			s.push(Node(row, col));
		}
		//回退 或 退出
		else if (!s.empty())
		{
			s.pop();
			row = s.top().row;
			col = s.top().col;
		}
	}
	vector<Node> result;
	while (!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	}
	reverse(result.begin(), result.end());
	for (auto e : result)
	{
		cout << "(" << e.row << "," << e.col << ")" << endl;
	}
}
int test()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<int>> v(n, vector<int>(m, 0));
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				cin >> v[i][j];
			}
		}
		get_path(v);
	}
	return 0;
}

int main()
{
	test();
	return 0;
}