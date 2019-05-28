class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        while(B)
        {
            //1.两数之和,不考虑进位
            int sum = A^B;
            //2.两数的进位，保留下来
            int carry = (A&B)<<1;
            A = sum;
            B = carry;
        }
        return A;
    }
};