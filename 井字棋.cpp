class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        //即每行、每列、对角线为3时表示赢了
        //检查每行之和是否为3
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
        //检查每列之和是否为3
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
        //检查对角线之和是否为3
        //检查主对角线
        int sum = 0;
        for(int i = 0;i<board.size();i++)
        {
               sum += board[i][i];
        }
        if(sum == 3)
            return true;
        //检查幅对角线
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