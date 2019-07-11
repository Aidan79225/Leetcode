class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] ans = new int[seq.length()];
        int group = 0;
        for (int i = 0; i < ans.length; i++) {
            char c = seq.charAt(i);
            if (c == '(') {
                ans[i] = group;
                group = (group+1) & 0b1;
            } else {
                group = (group+1) & 0b1;
                ans[i] = group;
            }
        }
        return ans;
    }
}
