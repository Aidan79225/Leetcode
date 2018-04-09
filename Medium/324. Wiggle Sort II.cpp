class Solution {
public:
    int n;
    void wiggleSort(vector<int>& nums) {
        n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[index(j)] > mid)
                swap(nums[index(i++)], nums[index(j++)]);
            else if (nums[index(j)] < mid)
                swap(nums[index(j)], nums[index(k--)]);
            else
                j++;
        }
    }
    int index(int i){
        return (1+2*(i)) % (n|1);
    }
 
};
