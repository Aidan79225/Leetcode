class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ans = 0;
        int status[10001] = {0};
        int dp[10001] = {0};
        int mMax = 0;
        for(auto& i : nums){
            status[i]++;
            mMax = max(i,mMax);
        }
        for(int i = mMax ; i > 0 ; i--){
            int t = status[i]*i;
            if(i+2 <= mMax){
                t += dp[i+2];
            }
            if(i+1 <= mMax){
                t = max(t, dp[i+1]);
            }
            dp[i] = t;
        }
        return dp[1];
    }
    
    int dfs(int status[10001], int index){
        if(index > 10000){
            return 0;
        }
        int used = status[index]*index + dfs(status, index+2);
        int notUsed = dfs(status, index+1);
        return max(used, notUsed);
    }
};
