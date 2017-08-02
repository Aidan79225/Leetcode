class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int nx = dungeon.size();
        int ny = dungeon[0].size();
        vector<vector<int>> dp(nx+1,vector<int>(ny+1,INT_MAX));
        dp[nx-1][ny-1] = 1 - dungeon[nx-1][ny-1];
        if(dp[nx-1][ny-1] <= 0) dp[nx-1][ny-1] = 1;
        
        for(int i = nx-1 ; i >= 0 ; i--){
            for(int j = ny-1 ; j >= 0 ; j--){
                if(i == nx-1 && j == ny-1)continue;
                dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];
                if(dp[i][j] <= 0) dp[i][j] = 1;
            }
        }
        return dp[0][0];
    }
};
