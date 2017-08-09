class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int mx = 0;        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0)continue;
            else{
                int index = i;
                int cur = 0;
                while(nums[index] >= 0){
                    int temp = index;
                    index = nums[index];
                    nums[temp] = -1;
                    cur++;
                }
                mx = max(mx,cur);
            }
        }
        return mx;
    }
};
