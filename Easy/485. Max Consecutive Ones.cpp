class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
               nums[i] = nums[i-1]+1;
               ans = max(nums[i],ans); 
            }
        }
        return ans;
    }
};
