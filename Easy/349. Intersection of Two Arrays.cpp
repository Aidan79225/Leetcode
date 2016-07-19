class Solution {
public:
    vector<vector<int>> hash;
    vector<vector<int>> hash2;
    const int hashSize = 41;
    bool checkContainOne(int num,vector<vector<int>>& hash ){
        vector<int>& container = hash[num%hashSize];
        for(int i=0;i<container.size();i++){
            if(num == container[i])
                return true;
        }
        return false;
    }
    bool checkContain(int num,vector<int>& container){
        for(int i=0;i<container.size();i++){
            if(num == container[i])
                return true;
        }
        return false;
    }
    void insertHash(int num,vector<vector<int>>& hash){
        vector<int>& temp = hash[num%hashSize];
        if(!checkContain(num,temp)){
            temp.push_back(num);
        }
            
    }
    void buildHash(vector<int>& nums){
        for(int i=0;i<hashSize;i++){
            vector<int> ans;
            hash.push_back(ans);
            hash2.push_back(ans);
        }
        for(int i=0;i<nums.size();i++){
            insertHash(nums[i],hash);
        }
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return intersection(nums2,nums1);
        } 
        vector<int> ans;
        buildHash(nums2);
        for(int i=0;i<nums1.size();i++){
            if(checkContainOne(nums1[i],hash) && !checkContainOne(nums1[i],hash2)){
                ans.push_back(nums1[i]);
                insertHash(nums1[i],hash2);
            }
                
        }
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        return ans;
    }
    
};
