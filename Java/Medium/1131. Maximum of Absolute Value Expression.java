class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int ans = Integer.MIN_VALUE;
        int[] op = new int[] {1, -1};
        for (int o1 : op) {
            for (int o2 : op) {
                int max = Integer.MIN_VALUE;
                int min = Integer.MAX_VALUE;
                for (int i = 0; i < arr1.length; ++i) {
                    max = Math.max(max, arr1[i] + arr2[i]*o1 + i*o2);
                    min = Math.min(min, arr1[i] + arr2[i]*o1 + i*o2);
                }
                ans = Math.max(ans, Math.abs(max-min));
            }
        }
        return ans;
    }
}
