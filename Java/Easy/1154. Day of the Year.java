class Solution {
    int[] md = {31, 59 ,90 ,120 , 151, 181, 212, 243, 273, 304, 334, 365};
    public int dayOfYear(String date) {
        int y = Integer.valueOf(date.substring(0,4));
        int m = Integer.valueOf(date.substring(5,7));
        int d = Integer.valueOf(date.substring(8));
        boolean oneMoreDay = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 4000 != 0);
        int ans = d;
        if (m - 2 >=0) {
            ans += md[m-2];
        }
        if (m > 2 && oneMoreDay) {
            ans-=-1;
        }       
        return ans;
    }
}
