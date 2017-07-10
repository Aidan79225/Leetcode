class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mMap;
        for(auto temp : wall){
            int count = 0;
            for(int j = 0 ; j < temp.size()-1 ; j++){
                count += temp[j];
                ++mMap[count];
            }
        }
        int ans = 0;
        for(auto temp : mMap){
            ans=max(ans,temp.second);
        }
        return wall.size()-ans;
    }
};
