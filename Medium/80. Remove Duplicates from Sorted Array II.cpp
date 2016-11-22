class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int count =1;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                if(count >= 2){
                    nums.erase(nums.begin()+i);
                    i--;
                }else{
                    count++;
                }
            }else{
                count = 1;
            }
        }
        return nums.size();
    }
};
