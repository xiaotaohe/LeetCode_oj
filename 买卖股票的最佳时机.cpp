
class Solution {
public:
    //���岨�ȷ�
    //1.����С���ȡ���󲨷�
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int min = prices[0];
        int max_ret = 0;
        //ֻ��Ҫһֱ���²��ȣ�ֻҪ���Ⱥ����ֵ�ܼ��������Ҵ����������
        for(int i = 1;i<prices.size();i++)
        {
            if(prices[i]<min)
                min = prices[i];
            else if(prices[i] - min > max_ret)
                max_ret = prices[i] - min;
        }
        return max_ret;
    }
};