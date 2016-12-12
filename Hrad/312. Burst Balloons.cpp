class Solution {
public:
    int maxCoins(int left,int right,vector<int>& nums,int* dp,int size){
        if(dp[left + right * size]>0)return dp[left + right * size];
        if(right - left == 1){
            return 0;
        }
        int max =0;
        for(int mid = left+1 ;mid < right; mid++){
            int temp = nums[mid]*nums[left] * nums[right] +maxCoins(left,mid,nums,dp,size) +maxCoins(mid,right,nums,dp,size);
            if(max <temp ){
                max = temp;
            }
        }
        dp[left + right * size] = max;
        return max;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int size = nums.size();
        int* dp;
        dp = (int*) malloc (size*size * sizeof(int));
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                dp[i + j * size]=0;
            }
        }
        return maxCoins(0,nums.size()-1,nums,dp,size);
    }
};
