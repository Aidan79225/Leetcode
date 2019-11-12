class Solution {
    public int longestSubsequence1(int[] arr, int difference) {
        int ans = 0;
        int[] step = new int[arr.length];
        HashMap<Integer, Integer> maxStep = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            step[i] = 1;
            Integer t = maxStep.get(arr[i] - difference);
            if (t != null) {
                step[i] = Math.max(step[i], t+1);
            }
            maxStep.put(arr[i], step[i]);
            ans = Math.max(step[i], ans);
        }
        return ans;
    }
    
    public int longestSubsequence(int[] arr, int difference) {
        int ans = 0;
        int[] step = new int[arr.length];
        int[] maxStep = new int[40001];
        for (int i = 0; i < arr.length; i++) {
            step[i] = 1;
            int t = maxStep[arr[i] - difference + 20000];
            if (t != 0) {
                step[i] = Math.max(step[i], t+1);
            }
            maxStep[arr[i] + 20000] = step[i];
            ans = Math.max(step[i], ans);
        }
        return ans;
    }
}
