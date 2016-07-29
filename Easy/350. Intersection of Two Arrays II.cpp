class Solution {
public:
    int hashMax = 41;
    vector<vector<int>> hashTable;
    vector<int> ans;
    void buildHash(vector<int>& nums){
        for(int i =0;i<nums.size();i++){
            hashTable[nums[i]%hashMax].push_back(nums[i]);
        }
    }
    void check(int num){
        vector<int>& temp = hashTable[num % hashMax];
        for(int i=0;i<temp.size();i++){
            if(temp[i] == num){
                ans.push_back(num);
                temp.erase(temp.begin() + i);
                return;
            }
        }
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())return intersect(nums2, nums1);
        hashTable = vector<vector<int>>(hashMax, vector<int>());
        buildHash(nums1);
        for(int i =0;i<nums2.size();i++){
            check(nums2[i]);
        }
        return ans;
    }
};
