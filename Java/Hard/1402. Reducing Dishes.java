class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int c = 0;
        int sum = 0;
        for (int i = satisfaction.length-1; i >= 0; --i) {
            int s = satisfaction[i];
            int k = c + sum + s;
            if (k > c) {
                c = k;
                sum += s;
            }
        }
        return c;
    }
}
