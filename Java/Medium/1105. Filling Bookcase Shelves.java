class Solution {
    public int minHeightShelves(int[][] books, int shelf_width) {
        int[] dp = new int[books.length + 1];
        dp[0] = 0;
        dp[1] = books[0][1];
        for (int i = 2; i <= books.length; i++) {
            int maxHeight = -1;
            int t = 0;
            int j;
            for (j = i-1; j >= 0; j--) {
                t += books[j][0];
                if (t <= shelf_width) {
                    maxHeight = Math.max(maxHeight, books[j][1]);
                    int threshold = dp[j]+ maxHeight;
                    dp[i] = dp[i] == 0 ? threshold : Math.min(threshold, dp[i]);
                } else {
                    break;
                }
            }
        }
        return dp[books.length];
    }
}
