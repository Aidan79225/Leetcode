class Solution {
    
public:
    int count =0;
    void solveSudoku(vector<vector<char>>& board) {
        int (*a)[9] = new int[9][9];
        init(a,board);
        if(solver(0,0,a)){
            slove(board,a);
        }
    }
    //解題器
    bool solver(int i,int j,int a[9][9]){
        if(i >= 9)return true;                          //全部跑完則完成
        if(j >= 9)return solver(i+1,0,a);               //這列跑完換到下一列
        if(a[i][j] > 0)return solver(i,j+1,a);          //已有值的禁止修改
        
        for (int k = 0; k < 9; k++) {                   //找到格子 格子有9個數字可填
            if (check(i,j,a,k+1)) {                     //check k+1這個數字是不是可以填
                a[i][j] = k+1;                          //可以填 就填 
                if (solver(i, j + 1,a )) return true;   //DFS
                else a[i][j] = 0;                       //填了失敗則填0 試下一個數字
            }
        }
        return false;
    }
    //check是否可填入target
    bool check(int x,int y,int a[9][9],int target){
        for(int i=0;i<9;i++){
            if(target == a[i][y])return false;           //第y行有出現則回傳false
            if(target == a[x][i])return false;           //第x列有出現則回傳false
        }
        int indexX = x/3*3;
        int indexY = y/3*3;
        for(int i = indexX; i < indexX+3; i ++){
            for(int j = indexY; j < indexY+3; j ++){
                if(target == a[i][j])
                    return false;
            }
        }

        return true;
    }
    
    
    void init(int a[9][9],vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                a[i][j] = 0;
                if(board[i][j] != '.'){
                    a[i][j] = board[i][j] - '0';
                }
            }
        }
        
    }
    
    void slove(vector<vector<char>>& board,int a[9][9]){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                board[i][j] = '0' + a[i][j];
            }
        }
    }


};
