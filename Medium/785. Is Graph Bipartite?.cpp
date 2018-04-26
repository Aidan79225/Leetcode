class Solution {
public:
    static const int red = 1;
    static const int black = -1;
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> status(graph.size(),0);
        for(int i = 0 ; i < graph.size() ; i++){
            if(status[i] == 0){
                if(dfs(graph,status,i,red)){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& status, int now, int color){
        status[now] = color;
        for(auto& it : graph[now]){
            if(status[it] == 0){
                if(dfs(graph,status,it,-color)){
                    return true;    
                }
            }else if(status[it] == color){
                return true;
            }
        }
        return false;
    } 
};
