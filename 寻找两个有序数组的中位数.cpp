class Solution {
public:
    //һ���������λ��
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
    //���������е���λ��
    double get_index2(vector<int>& nums1,vector<int>& nums2)
    {
       double min = 0,min1 = 0,min2 = 0,count = 0;
        double index = 0;
        //�����±�
        int index1 = 0,index2 = 0;
        //1.Ԫ�ظ���֮����ż������Ϊ��size/2 ��size/2+1��֮�ͳ��Զ�
        //2.��������λ��Ϊ��size/2+1;
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
        //������λ��
        double index = 0;
        //��һ��Ϊ��
        if(nums1.empty() ||nums2.empty())
        {
            if(!nums1.empty())
                index = get_index1(nums1);
            else
                index = get_index1(nums2);
        }
        //��������Ϊ��
        else
            index = get_index2(nums1,nums2);
        return index;
    }
};