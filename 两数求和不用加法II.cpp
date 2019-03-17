class UnusualAdd {
public:
    int addAB(int A, int B) {
        int sum = 0;
        int carry = 0;
        while(B)
        {
            //A^B�൱��A+B�����ǽ�λ
            sum = A^B;
            //A&B�൱��Ҫ����λ������1λ�պ�Ϊ��λ
            carry = (A&B)<<1;
            A = sum;
            B = carry;
        }
        return sum;
    }
};