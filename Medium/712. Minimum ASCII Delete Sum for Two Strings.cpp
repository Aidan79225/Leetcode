class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int **dp;
        dp = new int *[s1.size()+1];
        for(int i = 0 ; i <= s1.size(); i++){
            dp[i] = new int[s2.size()+1];
        }
        dp[0][0] = 0;
        for(int i = 1 ; i <= s1.size(); i++){
            dp[i][0] = s1[i-1] + dp[i-1][0];
        }
        for(int i = 1 ; i <= s2.size(); i++){
            dp[0][i] = s2[i-1] + dp[0][i-1];
        }
        for(int i = 1 ; i <= s1.size(); i++){
            for(int j = 1 ; j <= s2.size() ; j++){
                int carry = 0;
                if(s1[i-1] != s2[j-1]){
                    carry = s1[i-1] + s2[j-1];
                }
                
                dp[i][j] =min(dp[i-1][j-1] + carry, min(dp[i-1][j] + s1[i-1] , dp[i][j-1] + s2[j-1]));
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
