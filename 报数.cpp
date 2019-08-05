#include<string.h>

class Solution {
public:
    void getstr(string& str,string& ret)
    {
        int index = 0;
        int num = 0;
        while(index < str.size())
        {
            num = 1;
            char ch = str[index];
            index++;
            while(index<str.size() && str[index] == ch)
            {
                num++;
                index++;
            }
            ret += to_string(num);
            ret += ch;
        }
    }
    string countAndSay(int n) {
        string str = "1";
        string ret = "";
        if(n == 1)
            return "1";
        for(int i = 0;i<n-1;i++)
        {
            ret = "";
            getstr(str,ret);
            str = ret;
        }
        return ret;
    }
};