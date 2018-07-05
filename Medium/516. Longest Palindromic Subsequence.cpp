class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.length();
        string rs = "";
        for(auto i : s){
            rs = i + rs;
        }
        int dp[size+1][size+1];
        for(int i = 0 ; i <= size ; i++){
            for(int j = 0 ; j <= size ; j++){
                dp[i][j] = 0;
            }
        }
        int lc = 0, rc = 0;
        for(int i = 1 ; i <= size ; i++){
            for(int j = 1 ; j <= size ; j++){
                if(s[i-1] == rs[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        // for(int i = 0 ; i <= size ; i++){
        //     for(int j = 0 ; j <= size ; j++){
        //         cout<<dp[i][j]<<", ";
        //     }
        //     cout<<endl;
        // }
        return dp[size][size];
    }
};
