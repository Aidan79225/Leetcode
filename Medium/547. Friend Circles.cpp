
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<bool> v(n,false);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(M[i][i] == 1 && !v[i] ){
                ans++;
                dfs(M,i,v);
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& M, int i, vector<bool>& v){
        v[i] = true;
        for(int t = 0 ; t < M.size() ; t++){
            if(M[i][t] == 1 && !v[t]){
                dfs(M,t,v);    
            }
            
        }
    }
};
