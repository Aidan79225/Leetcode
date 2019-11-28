class Solution {
    public int longestDecomposition(String text) {
        return longestDecomposition(text, 0, text.length());
    }
    
    public int longestDecomposition(String text, int s, int e) {
        if (s >= e) {
            return 0;
        }
        int l = e - s;
        for (int i = 1; i <= l; ++i) {
            if (s+i > e-i) {
                return 1;
            }
            if (text.substring(s, s+i).equals(text.substring(e-i, e))) {
                return 2 + longestDecomposition(text, s+i, e-i);
            }
        }
        return 1;
    }
}
