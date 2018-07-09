class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>  mMap;
        for(auto it : strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            mMap[temp].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it : mMap){
            ans.push_back(it.second);
        }
        return ans;
    }
};
