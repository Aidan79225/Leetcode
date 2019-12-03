class Solution {
    public int numRollsToTarget(int d, int f, int target) {
        int[][] dp = new int[d+1][target+1];
        for (int i = 1; i <= f && i <= target; ++i) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= d; i++) {
            int top = i * f;
            for (int t = i; t <= target && t <= top; t++) {
                for (int sf = 1, tt = t-1; sf <= f && tt >= 0; ++sf, --tt) {
                    dp[i][t] += dp[i-1][tt];
                    dp[i][t] %= 1000000007;
                }
                    
            }
        }
        return dp[d][target];
    }
        
}
