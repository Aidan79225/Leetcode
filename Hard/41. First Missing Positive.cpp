class Solution {
public:
    void swap(int &a,int &b){
        int temp = a;
        a=b;
        b=temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            if(nums[i]>0 && nums[i] != i+1 && nums[i]<=nums.size()){
                swap(nums[i],nums[nums[i]-1]);
                if(nums[i] != i+1 && nums[i] != nums[nums[i]-1])
                    i--;
            }
        }
        for(int i =0;i<nums.size();i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};
