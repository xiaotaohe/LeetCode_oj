class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        string ans = strs[0];
        string tmp = "";
        for(int i = 1;i<strs.size();i++)
        {
            int j = 0;
            tmp = "";
            while(j<strs[i].size() && j<ans.size() && ans[j] == strs[i][j])
            {
                tmp += ans[j];
                j++;
            }
            ans = tmp;
        }
        return ans;
        
    }
};