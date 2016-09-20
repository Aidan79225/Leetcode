class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int temp ,size = nums.size();
        ans.push_back(1);
        for (int i = 1; i < size; ++i){
            temp = ans[i-1] * nums[i-1];
            ans.push_back(temp);
        }
        temp = nums[size - 1];
        for (int i = size - 2; i >= 0; --i){
            ans[i] *= temp;
            temp *= nums[i];
        }
        return ans;
    }
};
