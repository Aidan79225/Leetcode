class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int ans = 0;
        for (int i = 1; i < nums.length; i += 2) {
            int nei = nums[i-1];
            if (i + 1 < nums.length) {
                nei = Math.min(nums[i+1], nums[i-1]);   
            }
            if (nums[i] >= nei) {
                ans += nums[i] - nei + 1;
            }
        }
        
        int odd = 0;
        for (int i = 0; i < nums.length; i += 2) {
            int nei = Integer.MAX_VALUE;
            if ( i+1 < nums.length) {
                nei = nums[i+1];
            }
            
            if (i - 1 >= 0) {
                nei = Math.min(nei, nums[i-1]);   
            }
            
            if (nums[i] >= nei) {
                odd += nums[i] - nei + 1;
            }
        }
        return Math.min(ans, odd);
    }
}
