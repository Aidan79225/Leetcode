class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] c = new int[1001];
        for (int i : arr1) {
            c[i]++;
        }
        int index = 0;
        for (int i : arr2) {
            while (c[i]-- > 0) {
                arr1[index++] = i;
            }
        }
        for (int n = 0; n < 1001; n++) {
            while (c[n]-- > 0) {
                arr1[index++] = n;
            }
        }
        return arr1;
    }
}
