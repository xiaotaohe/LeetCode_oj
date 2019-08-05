class Solution {
public:
    bool isPalindrome(string s) {
       if(s.empty())
           return true;
        string str = "";
        for(int i = 0;i<s.size();i++)
        {
            if((s[i]<='9' && s[i]>='0') || (s[i]<='Z' && s[i]>='A') || (s[i]<='z' && s[i]>='a'))
            {
                //��дתСд
                if(s[i]<='Z' && s[i]>='A')
                     str += (s[i]+('a'-'A'));
                else 
                    str += s[i];
            }
        }
        s = str;
        reverse(str.begin(),str.end());
        if(str == s)
            return true;
        else
            return false;
    }
};