class Solution {
public:
    int StrToInt(string str) {
        if(str.size() == 0)
            return 0;
        int num = 0;
        bool flag = false;
        if(str[0] == '+' || str[0] == '-')
            flag = true;
        for(int i = 0;i<str.size();i++)
        {
            if(i == 0 && (str[i] == '+' || str[i] == '-'))
            {
                flag = true;
                continue;
            }
            if(str[i]>'9'||str[i]<'0')
                return 0;
            num = num*10 + (str[i]-'0');
        }
        if(flag == true)
        {
            if(str[0] == '-')
                num = 0 - num;
        }
        return num;
    }
};