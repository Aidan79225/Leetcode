int binarySerch(vector<int>& nums, int leftIndex, int rightIndex, int target){
    int midIndex = (leftIndex + rightIndex)/2,mid = nums[midIndex],left = nums[leftIndex],right = nums[rightIndex];
    cout<<"right : "<<rightIndex<<endl;
    cout<<"left  : "<<leftIndex<<endl;
    if(target == mid) return midIndex;
    if(target == left) return leftIndex;
    if(target == right) return rightIndex;
    
    if((rightIndex - leftIndex) <= 1)return leftIndex;
    if(target <mid)return binarySerch(nums,leftIndex,midIndex,target);
    else return binarySerch(nums,midIndex,rightIndex,target);
}
int findIndexForTarget(vector<int>& nums, int leftIndex, int rightIndex, int target){
    int midIndex = (leftIndex + rightIndex)/2,mid = nums[midIndex],left = nums[leftIndex],right = nums[rightIndex];
    cout<<"right : "<<rightIndex<<endl;
    cout<<"left  : "<<leftIndex<<endl;
    if(target == mid) return midIndex;
    if(target == left) return leftIndex;
    if(target == right) return rightIndex;
    if(rightIndex - leftIndex <= 1)return leftIndex;
    if(left < mid){
        if(target < mid){
            if(target < left)
                return findIndexForTarget(nums,midIndex,rightIndex,target);
            else
                return binarySerch(nums,leftIndex,midIndex,target);
        }
        else return findIndexForTarget(nums,midIndex,rightIndex,target);
    }else{
        if(target < mid)return findIndexForTarget(nums,leftIndex,midIndex,target);
        else {
            if(target < right)
                return binarySerch(nums,midIndex,rightIndex,target);
            else
                return findIndexForTarget(nums,leftIndex,midIndex,target);
        }
    }
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i,j;
        if(nums.size() == 0 )return -1;
        else if(nums.size() == 1)
            if(nums[0] == target)return 0;
            else return -1;
        i = findIndexForTarget(nums, 0, nums.size()-1,target);
        if(nums[i] == target) return i;
        else if(nums[i+1] == target) return i+1;
        else return -1;
    }
};
