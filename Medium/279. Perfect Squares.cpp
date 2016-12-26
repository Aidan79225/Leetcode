class Solution {
public:
    int numSquares(int n) {
        //定義dp[n]為 最少次方和  
        int dp[n+1] = {0};
        for(int i=1;i <= n;i++){
            dp[i] = i;
        }
        for(int i=1;i <= n;i++){
            int temp = dp[i];
            for(int j=1 ; j<n ; j++){  //逐次去尋找 每一個dp[i] - j*j 找到最小的+1就是這次最小值
                int temp2 = i - j*j ;
                if(temp2 < 0 )break;
                temp = min(temp, dp[temp2] + 1);
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};
