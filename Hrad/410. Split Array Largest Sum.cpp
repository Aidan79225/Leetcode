class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int size = nums.size();
        vector<vector<int>> dp(m,vector<int>(size,0));
        dp[0][0] = nums[0];
        for(int i = 1 ; i < size ; i++){
            dp[0][i] = dp[0][i-1] + nums[i];
        }
        for(int i = 1 ; i < m ; i++){
            for(int j = i ; j < size ; j++){
                int mMin = INT_MAX;
                int temp = 0;
                for(int k = j ; k >= i ; k--){
                    temp += nums[k];
                    mMin = min(mMin,max(temp,dp[i-1][k-1]));
                }
                dp[i][j] = mMin;
            }
        }
        return dp[m-1][size-1];
    }
};
