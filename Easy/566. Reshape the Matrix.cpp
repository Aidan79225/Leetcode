class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> ans;
        int rn = nums.size();
        int cn = nums[0].size();
        int max = rn * cn;
        if(max != r * c)return nums;
        int index = 0;
        for(int i = 0 ; i < r ; i++){
            vector<int> row;
            for(int j = 0 ; j < c ; j++){
                row.push_back(nums[ index / cn][ index % cn]);
                ++index;
            }
            ans.push_back(row);
        }
        return ans;
    }
};
