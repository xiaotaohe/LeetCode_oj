class Solution {
public:
    //一个数组的中位数
    double get_index1(vector<int>& nums)
    {
        double index = 0;
        if(nums.size()==1)
            return (double)nums[0];
       if(nums.size()%2==0)
            index = ((double)nums[nums.size() / 2] + (double)nums[nums.size() / 2 - 1]) / 2;
        else
            index = (double)nums[nums.size()/2];
        return index;
    }
    //两个数组中的中位数
    double get_index2(vector<int>& nums1,vector<int>& nums2)
    {
       double min = 0,min1 = 0,min2 = 0,count = 0;
        double index = 0;
        //两个下标
        int index1 = 0,index2 = 0;
        //1.元素个数之和是偶数个则为第size/2 和size/2+1个之和除以二
        //2.奇数，中位数为第size/2+1;
        while(count != (nums1.size()+nums2.size())/2+2)
        {
            if(count == (nums1.size()+nums2.size())/2)
                min1 = min;
            if(count == (nums1.size()+nums2.size())/2+1)
                min2 = min;
            if(index1<nums1.size()&&index2<nums2.size())
            {
                if(nums1[index1]<nums2[index2])
                {
                    min = nums1[index1];
                    index1++;
                }
                else
                {
                    min = nums2[index2];
                    index2++;
                }
            }
            else if(index1<nums1.size())
            {
                min = nums1[index1];
                index1++;
            }
            else if(index2<nums2.size())
            {
                min = nums2[index2];
                index2++;
            }
            count++;
        }
        if((nums1.size()+nums2.size())%2)
            return index = min2;
        else
            return index = (min1+min2)/2;
    }
        
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //保存中位数
        double index = 0;
        //有一个为空
        if(nums1.empty() ||nums2.empty())
        {
            if(!nums1.empty())
                index = get_index1(nums1);
            else
                index = get_index1(nums2);
        }
        //两个都不为空
        else
            index = get_index2(nums1,nums2);
        return index;
    }
};