class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        if(size == 0) return ans;
        
        int temp =0;
        for(int i =0;i<size;i++){
            int temp = abs(nums[i])-1;
            nums[temp] = -abs(nums[temp]);
        }
        for(int i =0;i<size;i++){
            if(nums[i] >0)ans.push_back(i+1);
        }
        return ans;
        
    }
};
