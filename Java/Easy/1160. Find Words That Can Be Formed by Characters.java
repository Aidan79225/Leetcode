class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] count = new int[26];
        for (char c : chars.toCharArray()) {
            ++count[c-'a'];
        }
        int ans = 0;
        for (String w : words) {
            if (canHandle(w, count)) {
                ans += w.length();
            }
        }
        return ans;
    }
    
    boolean canHandle(String w, int[] count) {
        int[] t = new int[26];
        for (char c : w.toCharArray()) {
            int index = c - 'a';
            if (t[index] == count[index]) {
                return false;
            }
            ++t[index];
        }
        return true;
    }
}
