int find(vector<int>& nums1, vector<int>& nums2, int nums1Left, int nums2Left, int target){
    if((nums1.size() - nums1Left) > (nums2.size() - nums2Left))
        return find(nums2, nums1, nums2Left, nums1Left, target);
    if((nums1.size() - nums1Left) == 0)
        return nums2[nums2Left + target-1];
    if(target == 1){
        if(nums1[nums1Left]>nums2[nums2Left]) return nums2[nums2Left];
        else return nums1[nums1Left];
    }
    int kLeft = target /2 ;
    if(kLeft > (nums1.size() - nums1Left)) 
        kLeft = (nums1.size() - nums1Left);
    int kRight = target - kLeft ;
    if(nums1[nums1Left+kLeft-1] > nums2[nums2Left + kRight-1])
        return find(nums1, nums2 , nums1Left, nums2Left + kRight, kLeft);
    else if(nums1[nums1Left+kLeft-1] < nums2[nums2Left + kRight-1])
        return find(nums1, nums2 , nums1Left + kLeft, nums2Left, kRight);
    else
        return nums1[nums1Left+kLeft-1];
}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = nums1.size() + nums2.size();
        if(mid % 2 ==1)
            return (double)find(nums1,nums2,0,0,mid/2 + 1);
        else 
            return ((double)find(nums1,nums2,0,0,mid/2 + 1) + (double)find(nums1,nums2,0,0,mid/2 ))/2.0;
    }
    
};
