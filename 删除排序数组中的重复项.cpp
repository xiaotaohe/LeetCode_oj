class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)
            return nums.size();
        int index = 0;
        while(index<nums.size())
        {
            if(index+1<nums.size() && nums[index] == nums[index+1])
                nums.erase(nums.begin()+index+1);
            else
                index++;
        }
        return nums.size();
    }
};