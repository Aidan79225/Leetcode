
class Solution {
public:
    bool check(int n,vector<int>& temp){
        for(int i=0;i<temp.size();i++){
            if(n == temp[i])
                return true;
        }
        return false;
    }
    bool insert(int n,vector<int>& temp){
        if(!check(n,temp)){
            temp.push_back(n);
            return true;
        }
        else
            return false;
    }
    bool containsDuplicate(vector<int>& nums) {
        int const hashMax = 41;
        vector<vector<int>> hash;
        for(int i=0;i<hashMax;i++){
            vector<int>  temp;
            hash.push_back(temp);
        }
        for(int i=0 ;i<nums.size();i++ ){
            vector<int>&  temp = hash[nums[i]%hashMax];
            if(!insert(nums[i],temp))return true;
        }
        return false;
    }
};
