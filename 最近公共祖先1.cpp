#include<vector>
class LCA {
public:
    void get_path(int root,vector<int>& v)
    {
        if(root == 0)
            return;
        get_path(root/2,v);
        v.push_back(root);
    }
    int getLCA(int a, int b)
    {
        // write code here
        if(a<b)
            swap(a,b);
        if(a == 1 || b == 1)
            return 1;
        vector<int> va;
        vector<int> vb;
        get_path(a,va);
        get_path(b,vb);
        int num = min(va.size()-1,vb.size()-1);
        for(int i = num;i>=0;i--)
        {
            if(va[i] == vb[i])
                return va[i];
        }
        return 1;
    }
};