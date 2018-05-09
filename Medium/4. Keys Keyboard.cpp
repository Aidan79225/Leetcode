class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        while(n > 1){
            int k = getFactor(n);
            ans += k;
            n /= k;
        }
        return ans;
    }
    int getFactor(int n){
        for(int ans = 2; ans < n; ans++){
            if(n % ans == 0){
                return ans;
            }
        }
        return n;
    }
    int minSteps1(int n) {
        int dp[1000] = {0};
        dp[0] = 0;
        dp[1] = 2;
        dp[2] = 3;
        dp[3] = 4;
        for(int i = 4 ; i < n ; i++){
            int mMin = i+1;
            int k = i+1;
            for(int j = 2 ; j < k; j++){
                if(k % j == 0){
                    mMin = min(mMin, dp[j-1]  + k / j);
                }
            }
            dp[i] = mMin;
        }
        return dp[n-1];
    }
};
