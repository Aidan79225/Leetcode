class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(ans,nums,temp,0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int index){
        ans.push_back(temp);
        for(int i = index ; i < nums.size() ; i++){
            if(i == index || nums[i-1] != nums[i]){
                temp.push_back(nums[i]);
                dfs(ans,nums,temp,i+1);
                temp.pop_back();
            }
            
        }
        
    }
    
};
