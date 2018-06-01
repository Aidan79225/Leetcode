class Solution {
public:
    int find(vector<int>& n){
        int left = 0;
        int right = n.size()-1;
        int mid;
        while(right > left+1){
            mid = (left+right)/2;
            if(n[left]<n[mid]){
                if(n[mid]<n[right]){
                    return n[left];
                }else if(n[mid]>n[right]){
                    left = mid;
                }else{
                    right--;
                }
            }else if(n[left]>n[mid]){
                if(n[mid]<n[right]){
                    right = mid;
                }else if(n[mid]>n[right]){
                    return n[right];
                }else{
                    right--;
                }
            }else{
                left++;
            }            
        }
        return min(n[left], n[right]);
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        return find(nums);
    }
    
    
    
    /*
        Status: Accepted
        Runtime: 7 ms
        Your runtime beats 94.49 % of cpp submissions.
    */
    int findMin1(vector<int>& nums) {
        int mMin = INT_MAX;
        for(auto& it : nums){
            mMin = min(it, mMin);
        }
        return mMin;
    }
};
