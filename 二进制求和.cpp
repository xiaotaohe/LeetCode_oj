#include<algorithm>
class Solution {
public:
    string addBinary(string a, string b) {
        //1.Ĭ��a�
        if(a.size()<b.size())
            swap(a,b);
        //2.���
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0,j = 0;//�������±����
        bool flag = false;//��λ��־
        while(i<a.size() && j<b.size())
        {
            //�жϱ��ν�λ���´��Խ�λ
            if(a[i] == '1' && b[j] == '1' && flag)
                a[i] = '1';
            //�ϴ��޽�λ�����ν����´��н�λ
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
                //�жϽ�λ���������´ν�λ
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