class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int size =  points.size() ;
        int ans = 0;
        for(int i =0 ; i<size ; i++){
            unordered_map<int, int> mMap;
            for(int j=0 ; j < size ; j++){
                int x = dis(points[i],points[j]);
                mMap[x]++;
            }
            for(auto& it : mMap){
                ans += it.second * (it.second-1);
            }
        }
        return ans;
    }
    int dis(pair<int, int> a,pair<int, int> b){
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        return dx * dx + dy * dy;
    }
};
