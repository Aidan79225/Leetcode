class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mMap; // value, index
        int count = 0;
        int ans = 0;
        mMap[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            count += (nums[i] ? 1 : -1);
            if(mMap.find(count) == mMap.end()){
                mMap[count] = i;
            }else{
                ans = max(ans, i - mMap[count]);
            }
        }
        return ans;
    }
};
