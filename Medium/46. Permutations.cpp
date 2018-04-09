class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans,nums,0,nums.size());
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& nums, int index, int size){
        if(index == size-1){
            ans.push_back(nums);
            return;
        } 
        for(int i = index ; i < size ; i++){
            swap(nums[i], nums[index]);
            dfs(ans,nums,index+1,size);
            swap(nums[i], nums[index]);
        }
    }
};
