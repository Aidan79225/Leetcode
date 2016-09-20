class Solution {
public:
    vector<int> solid;
    vector<int> shu;
    int size;
    Solution(vector<int> nums) {
        solid = nums;
        size = nums.size();
        for(int i=0;i<size;i++){
            shu.push_back(solid[i]);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return solid;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(size == 0)return shu;
        int r = rand() % size;
        int l = rand() % size;
        int temp = shu[r];
        shu[r] = shu[l];
        shu[l] = temp;
        
        return shu;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
