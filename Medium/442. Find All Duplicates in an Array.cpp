/*
 *  由於n個數 範圍為1 ~ n
 *  藉由 nums[i]當做一個新的index來看 把這個index所指向的數 標記成 -
 *  之後就逐個尋找 找到 nums[nums[i]] < 0 代表之前出現過了 就加入答案群
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        for(int i=0 ; i<size ; i++){
            int temp = abs(nums[i]) -1;
            if(nums[temp] < 0) ans.push_back(temp+1);
            else nums[temp] = -abs(nums[temp]);
        }
        return ans;
    }
};
