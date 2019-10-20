class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[][] temp = new int[10][10];
        int ans = 0;
        for (int[] dominoe : dominoes) {
            int i = Math.max(dominoe[0], dominoe[1]);
            int j = Math.min(dominoe[0], dominoe[1]);
            temp[i][j] += 1;
            if (temp[i][j] > 1) {
                ans += temp[i][j] - 1;
            }
        }
        return ans;
    }
}
