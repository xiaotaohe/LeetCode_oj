#include<iostream>
#include<assert.h>
using namespace std;

int main()
{
    //ì³²¨ÄÇÆõÊýÁÐ
    int month = 0;
    while(cin>>month)
    {
        assert(!(month<0));
        if(month<=2)
        {
            cout<<1<<endl;
            continue;
        }
        int temp = 0,f1 = 0,f2 = 1;
        for(int i = 1;i<month;i++)
        {
            temp = f1+f2;
            f1 = f2;
            f2 = temp;
        }
        cout<<temp<<endl;
    }
    return 0;
}