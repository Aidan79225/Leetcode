class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2)return nums.size();
        unordered_set<int> ans ;
        for(int i=0;i<nums.size();i++){
            ans.insert(nums[i]);
        }
        
        
        int maxcount = 0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int count = 0;
            while(ans.find(num) != ans.end()){
                ans.erase(num);
                num++;
                count++;
            }
            num = nums[i]-1;
            while(ans.find(num) != ans.end()){
                ans.erase(num);
                num--;
                count++;
            }
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};
