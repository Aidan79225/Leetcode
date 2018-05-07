class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<unordered_set<char>>> mMap(26,vector<unordered_set<char>>(26, unordered_set<char>()));
        for(auto& it : allowed){
            mMap[it[0]-'A'][it[1]-'A'].insert(it[2]);
        }
        int s = bottom.length();
        return dfs(bottom,0,mMap,(s*(s +1)>>1),0,s-1);
    }
    bool dfs(string status, int index, vector<vector<unordered_set<char>>>& mMap, int ans, int lineCount, int lineMax){
        if(lineMax == 0){
            return true;
        }
        if(lineCount == lineMax){
            return dfs(status, index+1, mMap, ans, 0, lineMax-1);
        }   
        for(auto&it : mMap[status[index]-'A'][status[index+1]-'A']){
            if(dfs(status+it,index+1,mMap,ans,lineCount+1,lineMax)){
                return true;
            }
        }   
        return false;
    }
};
