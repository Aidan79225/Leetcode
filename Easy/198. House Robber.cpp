class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        switch(n){
            case 0:return 0;
            case 1:return nums[0];
        }
        int ans[n] = {0};
        ans[0] = nums[0];
        ans[1] = nums[0]<nums[1]?nums[1]:nums[0];
        for(int i=2;i<n;i++){
            ans[i] = nums[i] + ans[i-2];
            if(ans[i]<ans[i-1])
                ans[i] = ans[i-1];
        }
        
        return ans[n-1];
    }
};
