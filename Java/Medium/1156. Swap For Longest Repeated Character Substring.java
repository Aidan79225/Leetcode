class Solution {
    public int maxRepOpt1(String text) {
        int size = text.length();
        int[] count = new int[size];
        char[] cs = new char[size];
        int last = -1;
        char t = '0';
        
        Map<Character, Integer> ci = new HashMap<>();
        for (char c : text.toCharArray()) {
            if (c != t) {
                ++last;
                cs[last] = c;
                t = c;
                ci.put(c, ci.getOrDefault(c, 0)+1);
            }
            ++count[last];
        }
        int ans = 0;
        for (int i = 0; i <= last; ++i) {
            int key = count[i];
            if (ci.getOrDefault(cs[i], 0) >= 2) {
                ++key;
            }
            ans = Math.max(ans, key);
        }
        
        for (int i = 1; i < last; ++i) {
            int key = 0;
            if (count[i] == 1 && cs[i-1] == cs[i+1]) {
                key = count[i-1] + count[i+1];
                if (ci.getOrDefault(cs[i-1], 0) > 2) {
                    ++key;
                }
            }
            ans = Math.max(ans, key);
        }
        return ans;
    }
}
