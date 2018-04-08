class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> status(nums.size(), false);
        while(isNotEnd(status)){
            vector<int> temp;
            for(int i = 0 ; i < nums.size() ; i++){
                if(status[i]){
                    temp.push_back(nums[i]);
                }
            }
            add(status);
            ans.push_back(temp);
        }
        ans.push_back(nums);
        return ans;
    }
    bool isNotEnd(vector<bool>& status){
        for(auto it : status){
            if(!it)return true;
        }
        return false;
    }
    void add(vector<bool>& status){
        if(!status[0]){
            status[0] = true;
        }else{
            for(int i = 0 ; i < status.size() ; i++){
                if(status[i]){
                    status[i] = false;
                }else{
                    status[i] = true;
                    break;
                }
            }
        }
        
    }
};
