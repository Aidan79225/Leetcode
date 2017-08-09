class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0)return 0;
        int ans = duration;
        for(int i = 1 ; i < timeSeries.size() ; i++){
            ans += min(  timeSeries[i] - timeSeries[i-1] ,duration);
        }
        return ans;
    }
};
