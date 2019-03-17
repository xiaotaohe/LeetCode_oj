class UnusualAdd {
public:
    int addAB(int A, int B) {
        int sum = 0;
        int carry = 0;
        while(B)
        {
            //A^B相当于A+B不考虑进位
            sum = A^B;
            //A&B相当于要进的位，左移1位刚好为进位
            carry = (A&B)<<1;
            A = sum;
            B = carry;
        }
        return sum;
    }
};