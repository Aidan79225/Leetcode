class Solution {
public:
    bool check(vector<char> c){
        for(int i = 0 ; i < 8 ; i++){
            for(int j = i+1 ; j < 9 ; j++){
                if(c[i] == c[j] && c[i] != '.')
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans =true;
        for(int i = 0;i<9;i++){
            ans = ans & check(board[i]);
        }
        vector<char> temp;
        for(int i=0;i<9;i++){
            temp.push_back(board[i][0]);
        }
        ans = ans & check(temp);
        for(int i = 1;i<9;i++){
            for(int j = 0 ; j < 9 ; j++){
                temp[j] = board[j][i];
            }
            ans = ans & check(temp);
        }
        int count = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                count =0;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        temp[count++] = board[ k + i*3 ][ l + j*3 ];
                    }
                }
                ans = ans & check(temp);
            }
        }
        return ans;
    }
};
