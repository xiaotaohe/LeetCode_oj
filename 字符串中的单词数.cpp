class Solution {
public:
    int countSegments(string s) {
       if(s.empty())
           return 0;
        int ret = 0;
        bool ch = false;//标识目前有没有遇到非空字符
        bool flag = true;//标识目前遇到的全为空字符
        //1.数空格数，标识是否全为空格
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                if(i+1<s.size() && s[i+1] != ' ' && ch)
                    ret++;
            }
            else
                flag = false;
            if(s[i] != ' ')
                ch = true;
        }
        //2.单词数等于空格数加1
        if(ret>0 || !flag)
            ret = ret+1;
        return ret;       
    }
};