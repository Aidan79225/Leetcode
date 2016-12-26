class Solution {
public:
    int numSquares(int n) {
        int dp[n+1] = {0};
        for(int i=1;i <= n;i++){
            dp[i] = i;
        }
        for(int i=1;i <= n;i++){
            int temp = dp[i];
            for(int j=1 ; j<n ; j++){
                int temp2 = i - j*j ;
                if(temp2 < 0 )break;
                temp = min(temp, dp[temp2] + 1);
                
                
            }
            dp[i] = temp;
        }
        
        
        return dp[n];
    }
};
