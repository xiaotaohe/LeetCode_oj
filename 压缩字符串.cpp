//ԭ���滻
#include<string>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty())
            return 0;
        int index = 0;//��ʶ��ǰҪ�޸ĵ�λ��
        int num = 1;//��ʶ�ظ�����
        char pre = chars[0];//��ʶ����εĵ�һ���ַ�
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
        //���һ���ĸ���δѹ
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


//�ȿ��ַ������滻
/*
#include<string>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty())
            return 0;
        //int index = 0;//��ʶ��ǰҪ�޸ĵ�λ��
        string str = "";
        int num = 1;//��ʶ�ظ�����
        char pre = chars[0];//��ʶ����εĵ�һ���ַ�
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
        //���һ��
        str += pre;
        if(num != 1)
            str += to_string(num);
        for(int i = 0;i<str.size();i++)
            chars[i] = str[i];
        return str.size();
    }
};
*/