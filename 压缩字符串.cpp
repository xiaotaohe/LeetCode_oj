//原地替换
#include<string>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty())
            return 0;
        int index = 0;//标识当前要修改的位置
        int num = 1;//标识重复个数
        char pre = chars[0];//标识连序段的第一个字符
        for(int i = 1;i<chars.size();i++)
        {
            if(pre == chars[i])
                num++;
            else if(num == 1)
            {
                chars[index] = pre;
                pre = chars[i];
                index++;
            }
            else 
            {
                chars[index] = pre;
                index++;
                string tmp = to_string(num);
                for(int j = 0;j<tmp.size();j++)
                    chars[index++] = tmp[j];
                pre = chars[i];
                num = 1;
            }
        }
        //最后一个的个数未压
        chars[index] = pre;
        index++;
        if(num != 1)
        {
            string tmp = to_string(num);
            for(int j = 0;j<tmp.size();j++)
                chars[index++] = tmp[j];
        }
        return index;
    }
};


//先开字符串，替换
/*
#include<string>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty())
            return 0;
        //int index = 0;//标识当前要修改的位置
        string str = "";
        int num = 1;//标识重复个数
        char pre = chars[0];//标识连序段的第一个字符
        for(int i = 1;i<chars.size();i++)
        {
            if(pre == chars[i])
                num++;
            else if(num == 1)
            {
                str += pre;
                pre = chars[i];
            }
            else 
            {
                str += pre;
                string tmp = to_string(num);
                str += tmp;
                pre = chars[i];
                num = 1;
            }
        }
        //最后一个
        str += pre;
        if(num != 1)
            str += to_string(num);
        for(int i = 0;i<str.size();i++)
            chars[i] = str[i];
        return str.size();
    }
};
*/