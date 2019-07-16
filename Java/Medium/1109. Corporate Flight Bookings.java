class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] ans = new int[n+1];
        for (int[] i : bookings) {
            ans[i[0]-1] += i[2];
            ans[i[1]] -= i[2];
        }
        int t = 0;
        for (int i = 0; i < ans.length; i++) {
            t += ans[i];
            ans[i] = t;
        }
        int[] a = new int[n];
        System.arraycopy(ans, 0, a, 0, n);
        return a;
    }
}
