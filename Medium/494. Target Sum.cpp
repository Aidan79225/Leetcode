class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int S) {
        map<int, map<int,int>> mDp;
        return findWays(nums,S);
    }
    //DP 轉換問題變成所有nums*2總合是否等於原本的nums總和+ S
    int findWays(vector<int>& nums, int S){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            nums[i] *= 2;
        }
        int t = S + sum;
        if(sum < S){
            return 0;
        }
        int dp[t+1] = {0};
        dp[0] = 1;
        for(int i = 0;i < nums.size(); i++){
    		for(int j = t;j >= 0;j--){
    			if(j >= nums[i]){
    				dp[j] += dp[j-nums[i]];
    			}
    		}
    	}
    	return dp[t];
    }
    //硬算
    int findWays(int i, int size, vector<int>& nums, int S) {
        if(i == size){
            if(S ==0){
                return 1;
            }
            return 0;
        }
        return findWays(i+1, size, nums, S-nums[i]) + findWays(i+1, size, nums, S+nums[i]);
    }
    //把算過的東西記起來 map<index,map<S,有幾種>>
    int findWays(int i, int size, vector<int>& nums, int S,map<int, map<int,int>>& mDp) {
        if(i == size){
            if(S ==0){
                return 1;
            }
            return 0;
        }
        map<int, map<int,int>>::iterator iter = mDp.find(i);
        if(iter != mDp.end()){
            map<int,int>::iterator iter2 = iter->second.find(S);
            if(iter2 != iter->second.end()){
                return iter2->second;
            }else{
                int ans = findWays(i+1, size, nums, S-nums[i],mDp) + findWays(i+1, size, nums, S+nums[i],mDp);
                iter->second[S] = ans;
                return ans;
            }
        }else{
            int ans = findWays(i+1, size, nums, S-nums[i],mDp) + findWays(i+1, size, nums, S+nums[i],mDp);
            map<int,int> newMap;
            newMap[S] = ans;
            mDp[i] = newMap;
            return ans;
        }
    }
    
};
