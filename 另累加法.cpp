class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        while(B)
        {
            //1.����֮��,�����ǽ�λ
            int sum = A^B;
            //2.�����Ľ�λ����������
            int carry = (A&B)<<1;
            A = sum;
            B = carry;
        }
        return A;
    }
};