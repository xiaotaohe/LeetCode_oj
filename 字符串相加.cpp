#include<algorithm>
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        //1.默认num1最长
        if(num1.size()<num2.size())
            swap(num1,num2);
        int i = 0,j = 0;//下标控制
        int flag = 0;//进位控制
        while(i < num1.size() && j < num2.size())
        {
            //进位
            if(num1[i]+num2[j]+flag-'0'-'0'>9)
            {
                num1[i] = num1[i]+num2[j]+flag-'0'- 10;
                flag = 1;
            }
            //不进位
            else
            {
                num1[i] = num1[i]+num2[j]+flag-'0';
                flag = 0;
            }
            i++;
            j++;
        }
        //处理剩余部分
        while(flag)
        {
            if(i < num1.size())
            {
                if(num1[i]+flag-'0'>9)
                    num1[i] = num1[i]+flag - 10;
                else
                {
                    num1[i] = num1[i]+flag;
                    flag = 0;
                }
            }
            else
            {
                num1.push_back('1');
                break;
            }
            i++;
        }
        reverse(num1.begin(),num1.end());
        return num1;
    }
};