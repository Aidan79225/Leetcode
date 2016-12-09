class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ;j < n ; j++){
                int temp = matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        int mid = n/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<mid;j++){
                int temp = matrix[i][j];
                matrix[i][j]= matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }
    }
};
