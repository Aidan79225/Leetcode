class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        bool count = false;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                if(count){
                    nums.erase(nums.begin()+i);
                    i--;
                }else{
                    count = true;
                }
            }else{
                count = false;
            }
        }
        return nums.size();
    }
};
