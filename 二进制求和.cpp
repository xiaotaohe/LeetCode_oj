#include<algorithm>
class Solution {
public:
    string addBinary(string a, string b) {
        //1.默认a最长
        if(a.size()<b.size())
            swap(a,b);
        //2.求和
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0,j = 0;//两个串下标控制
        bool flag = false;//进位标志
        while(i<a.size() && j<b.size())
        {
            //判断本次进位且下次仍进位
            if(a[i] == '1' && b[j] == '1' && flag)
                a[i] = '1';
            //上次无进位，本次结束下次有进位
            else if(a[i] == '1' && b[j] == '1' && flag == false)
            {
                a[i] = '0';
                flag = true;
            }
            else if((a[i] == '1' || b[j] == '1') && flag)
                a[i] = '0';
            else if((a[i] == '1' || b[j] == '1') && flag == false)
                a[i] = '1';
            else if(a[i] == '0' && a[i] == '0' && flag)
            {
                a[i] = '1';
                flag = false;
            }
            else if(a[i] == '0' && a[i] == '0' && flag == false)
                a[i] = '0';
            i++;
            j++;
        }
        while(flag)
        {
            if(i < a.size())
            {
                //判断进位，并重置下次进位
                if(a[i] == '1' && flag)
                    a[i] = '0';
                else if(a[i] == '0' && flag)
                {
                    a[i] = '1';
                    flag = false;
                }
                i++;
            }
            else
            {
                a.push_back('1');
                break;
            }
        }
        reverse(a.begin(),a.end());
        return a;
    }
};