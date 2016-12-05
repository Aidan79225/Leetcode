class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        for(int i=row-2;i>=0;i--){
            for(int j=0; j < triangle[i].size() ; j++){
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};