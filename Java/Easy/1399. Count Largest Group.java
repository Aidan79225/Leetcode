class Solution {
    public int countLargestGroup(int n) {
        int[] group = new int[37];
        for (int i = 1; i <= n; ++i) {
            ++group[getCount(i)];
        }
        int max = 0;
        for (int g: group) {
            max = Math.max(max, g);
        }
        int ans = 0;
        for (int g: group) {
            if (g == max) {
                ans++;
            }
        }
        return ans;
    }
    
    public int getCount(int n) {
        int ans = 0;
        while(n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
}
