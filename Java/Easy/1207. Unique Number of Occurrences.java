class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int [] t = new int[2001];
        for (int i : arr) {
            t[i+1000]++;
        }
        HashSet<Integer> set = new HashSet<>(2001);
        for (int i : t) {
            if (i != 0) {
                if (set.contains(i)) {
                    return false;
                } else {
                    set.add(i);
                }
            }
        }
        return true;
    }
}
