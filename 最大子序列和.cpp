class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = 0;
        vector<int> dp;
        dp.resize(nums.size());
        dp[0] = nums[0];
        max = dp[0];
        for(int i = 1;i<dp.size();i++)
        {
            dp[i] = 0;
            if(dp[i-1] + nums[i] > nums[i])
                dp[i] = dp[i-1] + nums[i];
            else
                dp[i] = nums[i];
            if(max < dp[i])
                max = dp[i];
        }
        return max;
    }
};