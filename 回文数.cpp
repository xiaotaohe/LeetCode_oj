class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x<=0 && x<=9)
            return true;
        //将x逆序
        int y = x;
        //rev保存逆序结果
        long long rev = 0; 
        while(y)
        {
            rev = rev*10+y%10;
            y /= 10;
        }
        if(rev == x)
            return true;
        return false;
    }
};