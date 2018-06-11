class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), [&](auto& a, auto& b){
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        int ans = 0;
        int count;
        int size = points.size();
        for(int i=0 ; i < size ; i++){
            ans++;
            count = 0;
            int key = points[i].second;
            for(int j = i + 1 ; j < size ; j++){
                if(key >= points[j].first){
                    count++;           
                    key = min(key, points[j].second);
                }else{
                    break;
                }
            }
            i += count;
        }
        return ans;
    }
};
