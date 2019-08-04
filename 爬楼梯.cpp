class Solution {
public:
    //1.公式 f(n) = f(n-1) + f(n-2);
    int climbStairs(int n) {
        int f1 = 0, f2 = 1;
        if(n <= 2)
            return n;
        for(int i = 1;i<n;i++)
        {
            int tmp = f1 + f2;
            f1 = f2;
            f2 = tmp;
        }
        return f1+f2;
    }
};