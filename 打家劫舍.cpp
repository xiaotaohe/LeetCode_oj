#include<math.h>
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(i == 1)
                nums[i] = max(nums[i],nums[i-1]);
            else
                nums[i] = max(nums[i-1],nums[i]+nums[i-2]);
        }
        return nums[nums.size()-1];
    }
};