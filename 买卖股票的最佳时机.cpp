
class Solution {
public:
    //波峰波谷法
    //1.找最小波谷、最大波峰
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int min = prices[0];
        int max_ret = 0;
        //只需要一直更新波谷，只要波谷后面的值能减过波谷且大于最大利润
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