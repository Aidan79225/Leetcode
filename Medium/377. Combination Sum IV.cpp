class Solution {
public:
    unordered_map<int,int> mMap;
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)return 1;
        if(mMap.find(target) != mMap.end())return mMap[target];
        int ans = 0;
        for(auto&it : nums){
            if(it <= target){
                ans += combinationSum4(nums,target - it);
            }
        }
        mMap[target] = ans;
        return ans;
    }
};
