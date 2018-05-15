class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mMap;
        vector<int> ans(2,0);
        for(int i = 0; i < nums.size(); i++){
            int k = target - nums[i];
            if(mMap.find(k) != mMap.end()){
                ans[0] = mMap[k];
                ans[1] = i;
                return ans;
            }
            mMap[nums[i]] = i;
        }
        return ans;
    }
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<vector<int>> hash;
        const int max = 47,size = nums.size();
        hash.resize(max);
        for (int i = 0; i < size; ++i){
            hash[abs(nums[i])%max].push_back(nums[i]);
        }
        
        vector<int> ans;
        for(int i = 0;i<size;i++){
            int temp = target - nums[i];
            bool flag = false;
            for(int j = 0;j<hash[abs(temp) % max].size();j++){
                if(temp == hash[abs(temp) % max][j]){
                    for(int j = 0;j<size;j++){
                        if(temp == nums[j] && j!=i){
                            ans.push_back(i);    
                            ans.push_back(j);
                            return ans;
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};
