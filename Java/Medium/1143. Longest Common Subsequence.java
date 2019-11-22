class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[2][text2.length() + 1];
        int old = 0;
        for (int i = 0; i < text1.length(); i++) {
            char c1 = text1.charAt(i);
            int newLine = 1 - old;
            for (int j = 0; j < text2.length(); j++) {
                char c2 = text2.charAt(j);
                dp[newLine][j+1] = Math.max(dp[newLine][j], dp[old][j+1]);
                if (c1 == c2) {
                    dp[newLine][j+1] = Math.max(dp[old][j] + 1, dp[newLine][j+1]);
                }
            }
            old = 1 - old;
        }
        return dp[old][text2.length()];
    }
}
