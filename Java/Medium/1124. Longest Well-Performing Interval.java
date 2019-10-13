class Solution {
    public int longestWPI(int[] hours) {
        int ans = 0;
        int cur = 0;
        int[] idx = new int[(hours.length<<1) + 1];
        Arrays.fill(idx, -1);
        for (int i = 0; i < hours.length; i++) {
            cur += hours[i] > 8 ? 1 : -1;
            if (cur > 0) {
                ans = Math.max(ans, i+1);
            } 
            int key = cur + hours.length;
            if (idx[key] == -1) {
                idx[key] = i;
            } 
            
            if (--key >= 0 && idx[key] != -1) {
                ans = Math.max(ans, i - idx[key]);
            }
            
        }
        return ans;
    }
}
