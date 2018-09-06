class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) { 
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ans = INT_MAX;
        int temp = INT_MAX;
        for(int i = 0; i < size-2; i++){
            int l = i + 1;
            int r = size - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                int key = sum - target;
                if(abs(key) < temp){
                    temp = abs(key);
                    ans = sum;
                }
                if(key == 0){
                    return sum;
                }else if(key > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};
