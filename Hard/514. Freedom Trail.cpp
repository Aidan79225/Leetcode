class Solution {
public:
    unordered_map<char, vector<int>> mMap;
    int ringSize;
    int ringHalf;
    int findRotateSteps(string ring, string key) {
        for(int i = 0 ; i < ring.size() ; i++){
            mMap[ring[i]].push_back(i);
        }
        ringSize = ring.size();
        ringHalf = (ringSize>>1);
        vector<vector<int>> dp(key.size(),vector<int>(ring.size(),-1));
        return findRotateSteps(dp,0,0,key);
    }
    int findRotateSteps(vector<vector<int>>& dp, int index, int position, string key) {
        if(index >= key.size())return 0;
        if(dp[index][position] != -1)return dp[index][position];
        int ans = 1;
        char keyC = key[index];
        vector<int> temp = mMap[keyC];
        int mMin = 2147483647;
        for(int i = 0 ; i < temp.size() ; i++){
            int distance = abs(temp[i] - position);
            if(distance > ringHalf ){
                distance = abs(ringSize - distance);
            }
            mMin = min(mMin, distance + findRotateSteps(dp,index + 1, temp[i],key ));
        }
        dp[index][position] = ans + mMin;
        return ans + mMin;
    }
};
