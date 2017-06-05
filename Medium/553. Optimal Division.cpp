// max = a / (min);
// min = all "/" is "/", not "*"

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = to_string(nums[0]);
        if(nums.size() > 2){
            ans += "/(";    
        }else if(nums.size() == 2){
            ans += "/";
        }
        for(int i = 1;i<nums.size()-1;i++){
            ans += to_string(nums[i]);
            ans += "/";
        }
        if(nums.size()>1)ans += to_string(nums[nums.size()-1]);
        if(nums.size() > 2){
            ans += ")";
        }
        return ans;
    }
    
};
