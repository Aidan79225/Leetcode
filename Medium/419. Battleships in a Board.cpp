class Solution {
public:
  
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0 )return 0;
        int column = board[0].size();
        if(column == 0 )return 0;
        
        int count =0;
        for(int i =0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j] == 'X'){
                    if( i > 0 && board[i-1][j] == 'X')
                        continue;
                    if( j > 0 && board[i][j-1] == 'X')
                        continue;
                    count ++;
                }
                
            }
        }
        return count;
    }
};
