class Solution {
public:
    static bool comparetor (pair<char,int> i,pair<char,int> j) { return (i.second > j.second); }
    string frequencySort(string s) {
        unordered_map<char,int> mMap;
        for(int i = 0 ; i < s.size() ; i++){
            mMap[s[i]]++;
        }
        
        vector<pair<char,int>> container;
        for(auto& it : mMap){
            container.push_back(it);
        }
        
        sort (container.begin(), container.end(), comparetor);
        string ans = "";
        for(int i = 0 ; i < container.size() ; i++){
            string tmp(container[i].second, container[i].first);
            ans += tmp;
        }
        return ans;
    }
};
