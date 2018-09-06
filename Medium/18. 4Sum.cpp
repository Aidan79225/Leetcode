class Solution {
public:
    class Trie {
        public:
            unordered_map<int, Trie*> nextMap;
            bool hasNext(vector<int>& nums, int index){
                if(index >= nums.size()){
                    return true;
                }
                if(nextMap.find(nums[index]) != nextMap.end()){
                    return nextMap[nums[index]] -> hasNext(nums, index+1);
                }else{
                    return false;
                }
            }
        
            void addNode(vector<int>& nums, int index){
                if(index >= nums.size()){
                    return;
                }
                if(nextMap.find(nums[index]) == nextMap.end()){
                    nextMap[nums[index]] = new Trie();   
                }
                nextMap[nums[index]] -> addNode(nums, index+1);
            }
    };
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int> temp(4,0);
        Trie* root = new Trie();
        for(int i = 0; i < size-3; ++i){
            int t = target - nums[i];
            for(int j = i+1; j < size-2 ; ++j){ // 3Sum
                int l = j + 1;
                int r = size-1;
                while(l < r){
                    int key = -(nums[l] + nums[r]) + t;
                    if(nums[j] > key){
                        r--;
                    }else if(nums[j] < key){
                        l++;
                    }else{
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[l];
                        temp[3] = nums[r];
                        if(!root -> hasNext(temp, 0)){
                            ans.push_back(temp);   
                            root -> addNode(temp, 0);
                        }
                        while(nums[r] == nums[--r]);
                        while(nums[l] == nums[++l]);
                    }
                }
            }
        }
        return ans;
    }
};
