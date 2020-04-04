class Solution {
    public boolean canConstruct(String s, int k) {
        char[] cs = s.toCharArray();
        int[] count = new int[26];
        for (char c: cs) {
            ++count[c-'a'];
        }
        int single = 0;
        int max = 0;
        for (int c: count) {
            if ((c&1) == 1) {
                ++single;
                --max;
            } 
            max += c;
        }
        return single == k || (single < k && k <= max + single);
    }
}
