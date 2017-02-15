class Solution {
public:
    static const int dead = 0;
    static const int live = 1;
    static const int liveToDead = 2; // 儲存狀態 原本 生 在下個世代 死
    static const int deadToLive = 3; // 儲存狀態 原本 死 在下個世代 生
    const int dx[3] = {-1,0,1};
    const int dy[3] = {-1,0,1};
    void gameOfLife(vector<vector<int>>& board) {
        int size = board.size();
        if(size == 0 )return;
        int wsize = board[0].size();
        if(wsize == 0)return;
        nextGame(0,0,size,wsize,board); //計算下個世代
        modifyToFitForm(size, wsize, board); //把liveToDead,deadToLive改成dead,live
    }
    void nextGame(int i,int j,int size,int wsize,vector<vector<int>>& board){
        if(j == wsize){
            return;
        }else if(i == size){
            nextGame(0,j+1,size,wsize,board);
            return;
        }else{
            switch(board[i][j]){
                case dead:
                    //Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if(count(i,j,size,wsize,board) == 3)board[i][j] = deadToLive; 
                    break;
                case live:
                    int ans = count(i,j,size,wsize,board);
                    //Any live cell with two or three live neighbors lives on to the next generation.
                    //Other numbers of neighbors will kill self
                    if(ans != 2 && ans != 3){
                        board[i][j] = liveToDead;
                    }
                    break;
            }
            nextGame(i+1,j,size,wsize,board);
        }
    }
    int count(int i,int j,int size,int wsize,vector<vector<int>>& board){ //count周圍live數量
        int ans = 0;
        for(int x=0 ; x<3 ; x++){ 
            for(int y=0 ; y<3 ; y++){
                int xx = i + dx[x];
                int yy = j + dy[y];
                if( checkForm(i,j,xx,yy,size,wsize) && (board[xx][yy] == 1 || board[xx][yy] == 2)){
                    ans++;
                }
            }
        }
        return ans;
    }
    bool checkForm(int i,int j,int xx,int yy,int size,int wsize){
        if(xx < 0)return false;
        if(xx >= size)return false;
        if(yy < 0)return false;
        if(yy >= wsize)return false;
        if(xx == i && yy == j)return false;
        return true;
    }
    void modifyToFitForm(int size, int wsize,vector<vector<int>>& board){
        for(int i =0 ; i<size ; i++ ){
            for(int j=0 ; j<wsize ; j++ ){
                if(board[i][j] >1){
                    board[i][j] -= 2;
                }   
            }
        }
    }
};
