class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        for(auto& it : nums){
            target += it;
        }
        if(target % k != 0){
            return false;
        }
        return check2(nums, target/k, k);
        // vector<int> kn(k, 0);
        // return check(target/k, nums, kn, 0);
    }
    
    
 
    bool check2(vector<int>& nums, int target,int k){
        sort(nums.begin(), nums.end());
        vector<int> mine(k,0);
        return dfs(nums.size()-1, nums, target, mine);
    }
    
    bool dfs(int index, vector<int>& nums, int target, vector<int>& mine){
        for(int i = 0 ; i < mine.size() ; i++){
            if(mine[i] + nums[index] > target){
                continue;
            }
            
            mine[i] += nums[index];
            if(index == 0)return true;
            if(dfs(index-1, nums, target, mine)){
                return true;
            }else{
                mine[i] -= nums[index];
                if(mine[i] == 0){
                    return false;   
                }
            }
        }
        return false;
        
    }
    
    
    bool dfs1(int target, vector<int>& nums, vector<int>& k, int index){
        if(index == nums.size()){
            return checkData(target, k);
        }
        for(auto& it : k){
            if(it == target){
                continue;
            }
            it += nums[index];
            if(dfs1(target, nums, k , index+1)){
                return true;
            }
            it -= nums[index];
            
        }
        return false;
    }
    
    bool checkData(int target, vector<int>& k){
        for(auto& i : k){
            if(target != i)return false;
        }
        return true;
    }
    
};
