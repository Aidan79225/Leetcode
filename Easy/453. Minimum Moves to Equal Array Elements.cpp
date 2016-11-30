class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int min = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            if(min > nums[i])min = nums[i];            
        }
        int ans =0;
        for(int i = 0 ; i < nums.size() ; i++){
            ans += nums[i] - min;
        }
        return ans;
        
    }
};
