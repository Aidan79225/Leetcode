class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length() + 1][text2.length() + 1];
        for (int i = 0; i < text1.length(); i++) {
            char c1 = text1.charAt(i);
            for (int j = 0; j < text2.length(); j++) {
                char c2 = text2.charAt(j);
                dp[i+1][j+1] = Math.max(dp[i+1][j], dp[i][j+1]);
                if (c1 == c2) {
                    dp[i+1][j+1] = Math.max(dp[i][j] + 1, dp[i+1][j+1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
}
