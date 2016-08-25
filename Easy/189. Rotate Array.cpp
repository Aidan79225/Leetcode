class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()>1){
            k=k%nums.size();
            vector<int> ans1 (&nums[nums.size()-k],&nums[nums.size()]);
            vector<int> ans2 (&nums[0],&nums[nums.size()-k]);
            ans1.insert(ans1.end(), ans2.begin(), ans2.end());
            nums = ans1;
        }
        
    }
};
