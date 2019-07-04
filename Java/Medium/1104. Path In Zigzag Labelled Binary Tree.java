class Solution {
    //[1,3,2,4,5,6,7,15,14,13,12,11,10,9 ,8 ,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,63]
    //[1,2,3,4,5,6,7,8 ,9 ,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32]
    public List<Integer> pathInZigZagTree(int label) {
        List<Integer> ans = new ArrayList<>();
        int lv = 0;
        int t = 1;
        while (label >= t) {
            lv++;
            t = (t<<1);
        }
        return zig(label, t, new ArrayList<Integer>());
    }
    
    public List<Integer> zig(int label, int t, List<Integer> ans) {
        ans.add(0, label);
        if (label == 1) {
            return ans;
        } else {
            return zig((t - label + ((t+1)>>1) -1)>>1, t>>1, ans);
        }
        
    }
}
