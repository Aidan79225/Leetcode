class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return vector<int>();
        int m = matrix[0].size();
        int i = 0, j = 0, count = 0;
        int v = -1;
        int maxC = n*m;
        vector<int> ans( maxC,0);
        while(count < maxC){
            ans[count++] = matrix[i][j];
            i += v;
            j -= v;
            if(j < 0){
                if(i == n){
                    i--;
                    j = 1;
                }else{
                    j = 0;   
                }
                v = -v;
            }else if(i < 0){
                if(j == m){
                    j--;
                    i = 1;
                }else{
                    i = 0;
                }
                v = -v;
            }else if(j == m){
                j = m-1;
                i +=2;
                v = -v;
            }else if(i == n){
                i = n-1;
                j += 2;
                v = -v;
            }
            
        }
        return ans;
    }
};
