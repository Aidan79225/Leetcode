class Solution {
    public int nthUglyNumber(int n) {
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        int[] dp = new int[n];
        dp[0] =1;
        for (int i = 1; i < n; i++) {
            int t2 = dp[index2]*2;
            int t3 = dp[index3]*3;
            int t5 = dp[index5]*5;
            int min = Math.min(Math.min(t2, t3), t5);
            dp[i] = min;
            if (t2 == min) {
                index2++;
            }
            if (t3 == min) {
                index3++;
            }
            if (t5 == min) {
                index5++;
            }
        }
        return dp[n-1];
    }
}
