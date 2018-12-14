class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp(rods.size(), vector<int>(10001, INT_MIN));
        return dfs(0, rods, 5000, dp);
    }
    
    int dfs(int index, vector<int>& rods, int t, vector<vector<int>>& dp) {
        if(index == rods.size()) {
            return t == 5000 ? 0 : INT_MIN;
        }
        if (dp[index][t] != INT_MIN) {
            return dp[index][t];
        }
        
        int ans = dfs(index+1, rods, t, dp);
        ans = max(ans, dfs(index+1, rods, t + rods[index], dp));
        ans = max(ans, rods[index] + dfs(index+1, rods, t - rods[index], dp));
        dp[index][t] = ans;
        return ans;
        
    }
    
    int tallestBillboard1(vector<int>& rods) {
        return getTallest(0, rods, 0, 0, 0);
    }
    
    int getTallest(int index, vector<int>& rods, int r, int l, int ans){
        if (index == rods.size()) {
            return ans;
        }
        
        if (r > l) {
            return getTallest(index, rods, l, r, ans);
        }
        
        int tr = r + rods[index];
        int ansr = tr == l ? tr : ans;
        ans = max(ans, getTallest(index+1, rods, tr, l, ansr));
        
        
        int tl = l + rods[index];
        int ansl = tl == r ? tl : ans;
        ans = max(ans, getTallest(index+1, rods, r, tl, ansl));
        
        ans = max(ans, getTallest(index+1, rods, r, l, ans));
        
        return ans;
        
    }
};
