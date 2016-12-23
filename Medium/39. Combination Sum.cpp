class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(ans,candidates,temp,target,0);
        return ans;
    }
//     利用temp當一個stack 來做 DFS 
//     每次從index開始走  避免重複 
//     target==0代表已找到一組答案 target<0代表走過頭 下去沒路了
    void combinationSum(vector<vector<int>> &ans,vector<int>& candidates,vector<int>& temp, int target,int index) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }else if(target <0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            combinationSum(ans,candidates,temp,target-candidates[i],i);
            temp.pop_back();
        }
        
    }
    
};
