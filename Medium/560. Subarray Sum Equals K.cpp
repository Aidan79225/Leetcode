class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> dp;
        dp[0]=1;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            ans += dp[sum - k];
            dp[sum]++;
        }   
        return ans;
    }
};
