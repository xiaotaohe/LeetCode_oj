#include<iostream>
using namespace std;
#include<vector>

void path(int flow,vector<int>& path)
{
    while(flow != 1)
    {
        path.push_back(flow);
        flow = flow/2;
    }
}
int get_root(int begin,vector<int> len,vector<int> str)
{
    int index = 0;
    int root = 0;
    for(int i = begin;i<len.size();i++)
    {
        if(len[i] == str[index++])
        {
            root = len[i];
            break;
        }
    }
    return root;
}
class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        //找到a，b到根节点的路径
        int root = 1;
        vector<int> path_a;
        vector<int> path_b;
        path(a,path_a);
        path(b,path_b);
        //截取路径长的那部分，从等长部分开始找起
        if(path_a.size()>path_b.size())
        {
            root = get_root(path_a.size()-path_b.size(),path_a,path_b);
        }
        else if(path_a.size()<path_b.size())
        {
            root = get_root(path_b.size()-path_a.size(),path_b,path_a);
        }
        else
            root = get_root(0,path_b,path_a);
        if(root == 0)
            root = 1;
        return root;
    }
};