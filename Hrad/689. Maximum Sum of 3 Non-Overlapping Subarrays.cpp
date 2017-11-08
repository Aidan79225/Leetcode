class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<int>> mMax(3,vector<int>(nums.size(),0));
        int kTemp = 0;
        for(int n = 0 ; n < 3; n++){
            kTemp += k;
            for(int i = 0 ; i < kTemp; i++){
                mMax[n][kTemp-1] += nums[i];
            }
            int sum = 0;
            for(int j = kTemp-1,c = 1 ; c < k ; c++,j-- ){
                sum += nums[j];
            }
            for(int i = kTemp ; i < nums.size(); i++){
                sum += nums[i];
                mMax[n][i] = max(mMax[n][i-1],sum + (n == 0? 0 :mMax[n-1][i-k] ));
                sum -= nums[i-k+1];
            }    
        }
        
        int temp = mMax[2][nums.size()-1];
        int a[3] = {0};
        int i = nums.size() - 1;
        for(int n = 2 ; n >= 0 ; n-- ){
            while(i>=0){
                if(temp == mMax[n][i]){
                    a[n] = i;
                }else{
                    break;
                }
                i--;
            }
            if(n != 0 ){
                i = a[n] - k;
                temp = mMax[ n - 1 ][ a[n] - k ];    
            }
            a[n] -= (k-1);    
        }
        
        vector<int> ans;
        for(int i = 0 ; i < 3 ; i++ ){
            ans.push_back(a[i]);    
        }
        return ans;
        
    }
};
