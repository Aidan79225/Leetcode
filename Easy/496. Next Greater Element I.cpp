class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mMap; //value,NextGreater
        for( int i = 0 ; i<nums.size() ; i++ ){
            bool notContain = true;
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(nums[i] < nums[j]){
                    mMap[nums[i]] = nums[j];
                    notContain = false;
                    break;
                }
            }
            if(notContain){
                mMap[nums[i]] = -1;
            }
        }
        for(int i = 0 ; i < findNums.size() ; i++){
            ans.push_back(mMap[findNums[i]]);
        }
        return ans;
    }
};
