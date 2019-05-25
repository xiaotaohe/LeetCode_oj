#include<iostream>
using namespace std;
#include<vector>

#if 0
//这个思路完全是错的，40%
//欧几里得距离是算术平方根，刚开始没看到算数平方根
int main()
{
    int col,row;
    int count = 0;
    cin>>col>>row;
    //1.如果是一维数组，那么最多可以放一位数组的大小个蛋糕
    if(col*row == row || col*row == col)
        count = col*row;
    //2.如果是高维的，便可每个一个取这一列来放蛋糕
    //比如 2行3列 可以取0、2列
    //如果 3行2列 可以取0、2行
    //所以可以将最大行或者最大列，然后隔行或隔列，取这一整列或者一整行来放蛋糕
    else
    {
        if(col>row)
            swap(col,row);
        for(int i = 0;i<row;i++)
        {
            if(i%2 == 0)
                count+=col;
        }
    }
    cout<<count<<endl;
}
#endif

//分析：欧几里得算术距离不能等于二，也就是任意两个蛋糕四周距离为2的地方都不能方蛋糕
//贪心算法
//1.二维数组，初始全放1，表示放蛋糕
//2.开始从左到右，从上到下，将放了蛋糕（ifa[i][j] == 1）的地方四周全置0

int main()
{
    int col = 0,row = 0;
    cin>>col>>row;
    vector<vector<int>> v;
    v.resize(row);
    for(int i = 0;i<row;i++)
        v[i].resize(col);
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
            v[i][j] = 1;
    }
    //贪心算法
    int count = 0;
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
            if(v[i][j] == 1)
            {
                if(i-2>=0)//上
                    v[i-2][j] = 0;
                if(i+2<row)//下
                    v[i+2][j] = 0;
                if(j-2>=0)//左
                    v[i][j-2] = 0;
                if(j+2<col)
                    v[i][j+2] = 0;
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}