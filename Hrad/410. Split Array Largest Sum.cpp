class Solution {
public:
    using ll = long long;

    bool canSplit(vector<int>& nums, int m, ll sum) {   // 把nums分成每堆剛好大於sum後 最多可以分成幾堆
        int c = 1;
        ll s = 0;
        for (auto& num : nums) {
            s += num;
            if (s > sum) {
                s = num;
                ++c;
            }
        }
        return c <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        ll left = 0, right = 0;
        for (auto& num : nums) {
            left = max(left, (ll)num);      //最小值  = 分成nums.size()堆
            right += num;                   //最大值
        }
        while (left <= right) {
            ll mid = left + (right-left)/2;
            if (canSplit(nums, m, mid))
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
    }
    
    int splitArrayDp(vector<int>& nums, int m) {
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
