class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1)return;
        int transfer = 0, 
            size = nums.size();
        for(int i=0;i<size-transfer;i++){
            while(nums[i+transfer] == 0 && i+transfer<size)transfer++;
            if(i+transfer>=size)break;
            nums[i] = nums[i+transfer];
        }
        for(int i=size-transfer;i<size;i++)
            nums[i]=0;
    }
};
