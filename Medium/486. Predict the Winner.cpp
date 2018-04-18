class Solution {
public: 
    vector<vector<int>> dp;
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() <= 2)return true;
        dp = *new vector<vector<int>>(nums.size(), vector<int>(nums.size(),INT_MIN));
        return minimax(nums,0,nums.size()-1) >= 0;
    }
    
    int minimax(vector<int>& nums, int l, int r){
        if(dp[l][r]>INT_MIN){
            return dp[l][r];
        }else{
            int ans = l == r ? nums[l] : max(nums[l] - minimax(nums,l+1,r), nums[r] - minimax(nums,l,r-1)) ;
            dp[l][r] = ans;
            return ans;
        }
    }
    
};
