class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        if(graph.size() == 0)return ans;
        int now = 0;
        vector<int> temp;
        temp.push_back(0);
        dfs(graph,temp, now, ans);
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph,vector<int>& status, int now, vector<vector<int>>& ans){
        if(now == graph.size()-1){
            ans.push_back(vector<int>(status.begin(),status.end()));
        }else{
            for(auto& it : graph[now]){
                status.push_back(it);
                dfs(graph, status, it,ans );
                status.pop_back();
            }    
        }
    }
};
