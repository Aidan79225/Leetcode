class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        dfs(ans,t,k,n,0,0);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& now, int k, int n, int ci, int cn){
        if(n == 0 ){
            if(ci == k){
                ans.push_back(now);    
            }
            return;
        }
        for(int i = cn+1 ; i <= 9 ; i++){
            now.push_back(i);
            dfs(ans,now,k, n-i, ci+1, i);
            now.pop_back();
        }
    }
};
