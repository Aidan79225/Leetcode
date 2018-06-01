class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1];
        for(int i = 0 ; i <= word1.length(); i++){
            dp[i][0] = i;
        }
        for(int i = 0 ; i <= word2.length(); i++){
            dp[0][i] = i;
        }
        for(int i = 1 ; i <= word1.length() ; i++){
            for(int j = 1 ; j <= word2.length() ; j++){
                int def = 1;
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j-1] + 2;
                }
                dp[i][j] = min(dp[i][j], min(dp[i-1][j]+ 1,dp[i][j-1]+ 1));
            }
        }
        return dp[word1.length()][word2.length()];
    }
};
