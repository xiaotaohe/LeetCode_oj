class Solution {
public:
    int countSegments(string s) {
       if(s.empty())
           return 0;
        int ret = 0;
        bool ch = false;//��ʶĿǰ��û�������ǿ��ַ�
        bool flag = true;//��ʶĿǰ������ȫΪ���ַ�
        //1.���ո�������ʶ�Ƿ�ȫΪ�ո�
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
        //2.���������ڿո�����1
        if(ret>0 || !flag)
            ret = ret+1;
        return ret;       
    }
};