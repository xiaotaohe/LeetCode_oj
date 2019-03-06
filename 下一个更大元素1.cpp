#include<map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;
        if(findNums.empty()||nums.empty())
            return ret;
        map<int,int> largemap;
        stack<int> st;
        //使用单调栈
        for(int i = 0;i<nums.size();i++)
        {
            //如果下一个元素比栈顶小，入栈
            if(st.empty()||st.top()>nums[i])
            {
                st.push(nums[i]);
                continue;
            }
            //如果下一个元素比栈顶大，栈顶出栈，此时该元素为栈顶元素下一个较大的元素
            //通过，保留栈顶和当前元素的键值对关系构建起来。
            while(!st.empty()&&st.top()<nums[i])
            {
                largemap.insert(pair<int,int>(st.top(),nums[i]));
                st.pop();
            }
            st.push(nums[i]);
        }
        for(int i = 0;i<findNums.size();i++)
        {
            //如果findNus的元素中，则map的value便是findNums[i]的下一个较大的元素。
            if(largemap.count(findNums[i]))
                ret.push_back(largemap[findNums[i]]);
            else
                ret.push_back(-1);
        }
        return ret;
    }
};