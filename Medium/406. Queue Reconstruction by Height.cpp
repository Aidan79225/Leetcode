class Solution {
public:
    static bool mComparetor (pair<int, int> i,pair<int, int> j) { 
        return i.first == j.first ?  i.second < j.second : i.first > j.first ; 
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), mComparetor);
        vector<pair<int, int>> ans;        
        for(auto p : people){
            ans.insert(ans.begin() + p.second, p);
        }
        return ans;
    }
};
