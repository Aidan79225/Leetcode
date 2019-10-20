class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[][] temp = new int[10][10];
        int ans = 0;
        for (int[] dominoe : dominoes) {
            if (dominoe[0] > dominoe[1]) {
                ans += temp[dominoe[0]][dominoe[1]]++;
            } else {
                ans += temp[dominoe[1]][dominoe[0]]++;
            }
        }
        return ans;
    }
}
