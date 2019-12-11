class Solution {
    public int countBinarySubstrings(String s) {
        int[] t = new int[s.length()];
        char ct = 'x';
        int last = -1;
        int unit = 1;
        char[] cr= s.toCharArray();
        for (int i =0; i < cr.length; ++i) {
            char c = cr[i];
            if (c != ct) {
                unit *= -1;
                ++last;
                t[last] = unit;
            } else {
                t[last] += unit;
            }
            ct = c;
        }
        int ans = 0;
        for (int i = 1; i <= last; ++i) {
            ans += Math.min(Math.abs(t[i]), Math.abs(t[i-1]));
        }
        return ans;
    }
}
