class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return bin(nums,0,nums.size()-1);
    }
    int bin(vector<int>& nums, int left ,int right){
        if(left == right)return nums[left];
        int mid = (left + right) / 2;
        if(nums[mid] == nums[mid+1]){
            mid = mid-1;
        }
        if( ( mid - left + 1 ) % 2 != 0){
            return bin(nums,left,mid);
        }else{
            return bin(nums,mid+1,right);
        }
    }
};
