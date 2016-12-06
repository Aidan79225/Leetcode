class Solution {
public:
    vector<int> n;
    
    Solution(vector<int> nums) {
        n = nums;
    }
    
    int pick(int target) {
        vector<int> index;
        for(int i=0;i<n.size();i++){
            if(target == n[i])
                index.push_back(i);
        }
        int ans = rand() % index.size();
        return index[ans];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
