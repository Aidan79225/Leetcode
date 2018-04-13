class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mMap;
        int ans = 0;
        for(auto& it : answers){
            mMap[it]++;
        }
        for(auto& it : mMap){
            ans += (it.first + 1) * ceil(it.second / (double)(it.first + 1));
        }
        return ans;
    }
};
