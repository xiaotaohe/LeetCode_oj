#include<map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;
        if(findNums.empty()||nums.empty())
            return ret;
        map<int,int> largemap;
        stack<int> st;
        //ʹ�õ���ջ
        for(int i = 0;i<nums.size();i++)
        {
            //�����һ��Ԫ�ر�ջ��С����ջ
            if(st.empty()||st.top()>nums[i])
            {
                st.push(nums[i]);
                continue;
            }
            //�����һ��Ԫ�ر�ջ����ջ����ջ����ʱ��Ԫ��Ϊջ��Ԫ����һ���ϴ��Ԫ��
            //ͨ��������ջ���͵�ǰԪ�صļ�ֵ�Թ�ϵ����������
            while(!st.empty()&&st.top()<nums[i])
            {
                largemap.insert(pair<int,int>(st.top(),nums[i]));
                st.pop();
            }
            st.push(nums[i]);
        }
        for(int i = 0;i<findNums.size();i++)
        {
            //���findNus��Ԫ���У���map��value����findNums[i]����һ���ϴ��Ԫ�ء�
            if(largemap.count(findNums[i]))
                ret.push_back(largemap[findNums[i]]);
            else
                ret.push_back(-1);
        }
        return ret;
    }
};