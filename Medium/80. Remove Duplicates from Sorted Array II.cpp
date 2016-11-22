class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int count = 2;
        for(int i =0;i<nums.size()-1;i++){
            if((i+count) < nums.size() && nums[i] == nums[i+count]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};
