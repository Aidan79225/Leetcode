class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        int temp =0;
        for(int i=0;i<size;i++){
            temp ^= nums[i];
        }
        int bitFlag = (temp & (~ (temp - 1)));
        int ans1=0,ans2=0;
        for(int i=0;i<size;i++){
            if((nums[i] & bitFlag)==0){
                ans1 ^= nums[i];   
            }else{
                ans2 ^= nums[i];
            }
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
