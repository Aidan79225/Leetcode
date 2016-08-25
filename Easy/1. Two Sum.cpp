class Solution {
public:
    int abs(int a){
        return a > 0 ? a:-a;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
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
                    flag = true;
                    break;
                }
            }
            if(flag){
                for(int j = 0;j<size;j++){
                    if(temp == nums[j] && j!=i){
                        ans.push_back(i);    
                        ans.push_back(j);
                        return ans;
                    }
                }
            }
        }
        return ans;
        
    }
};
