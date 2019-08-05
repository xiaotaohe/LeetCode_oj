class NumArray {
public:
    vector<int> ret;
    NumArray(vector<int>& nums) {
        if(nums.empty())
            return;
        ret = nums;
        int i,j;
        for(int i = 1;i<ret.size();i++)
            ret[i] += ret[i-1];
        while(cin>>i>>j)
            sumRange(i,j);
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return ret[j];
        else
            return ret[j]-ret[i-1];
    }
};
