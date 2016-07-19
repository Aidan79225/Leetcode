class Solution {
public:
    int find(vector<int>& n,int left,int right){
        int mid = (left+right)/2;
        if((right-left)==1)return n[left]<n[right]?n[left]:n[right];
        if(n[left]<n[mid]){
            if(n[mid]<n[right]){
                return n[left];
            }else if(n[mid]>n[right]){
                return find(n,mid,right);
            }else{
                return find(n,left,right-1);
            }
        }else if(n[left]>n[mid]){
            if(n[mid]<n[right]){
                return find(n,left,mid);
            }else if(n[mid]>n[right]){
                return n[right];
            }else{
                return find(n,left,right-1);
            }
        }else{
            return find(n,left+1,right);
        }
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        return find(nums,0,nums.size()-1);
    }
};
