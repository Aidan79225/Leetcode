class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> xtoy;
        for(auto& it : points){
            xtoy[it[0]].insert(it[1]);
        }
        int ans = 0;
        for(auto i = xtoy.begin(); i != xtoy.end(); ++i){
            if(i -> second.size() < 2) continue;
            for(auto j = next(i); j != xtoy.end(); ++j){
                if(j -> second.size() < 2) continue;
                vector<int> y;
                set_intersection(begin(i->second), end(i->second),
                begin(j->second), end(j->second), inserter(y, y.begin()));
                sort(y.begin(), y.end());
                for (int k = 1; k < y.size(); ++k){
                    int area = abs(j->first - i->first) * (y[k] - y[k - 1]);
                    ans = (ans == 0 ? area : min(ans, area));
                }
            }
        }
        return ans;
    }
};
