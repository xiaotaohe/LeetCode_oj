class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        //��ÿ�С�ÿ�С��Խ���Ϊ3ʱ��ʾӮ��
        //���ÿ��֮���Ƿ�Ϊ3
        for(int i = 0;i<board.size();i++)
        {
            int sum = 0;
            for(int j = 0;j<board[0].size();j++)
            {
                sum += board[i][j];
            }
            if(sum == 3)
                return true;
        }
        //���ÿ��֮���Ƿ�Ϊ3
        for(int i = 0;i<board.size();i++)
        {
            int sum = 0;
            for(int j = 0;j<board[0].size();j++)
            {
                sum += board[j][i];
            }
            if(sum == 3)
                return true;
        }
        //���Խ���֮���Ƿ�Ϊ3
        //������Խ���
        int sum = 0;
        for(int i = 0;i<board.size();i++)
        {
               sum += board[i][i];
        }
        if(sum == 3)
            return true;
        //�����Խ���
        sum = 0;
        int col = board.size()-1;
        for(int i = 0;i<board.size();i++)
        {
            sum += board[i][col--];
        }
        if(sum == 3)
            return true;
        return false;
    }
};