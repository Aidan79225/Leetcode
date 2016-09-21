class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans =0;
        int size = nums.size();
        int avg = ((size+1) >> 1);
            for(int i=0;i<size;i++){
                ans += avg - nums[i];
            }
        return size & 0b1 == 1 ? ans : ans + avg;
    }
};
