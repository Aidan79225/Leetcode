class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3){
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        int size = nums.size();
        vector<int> temp(3,0);
        for(int i = 0; i < size-2 && nums[i] <= 0; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i + 1;
            int r = size-1;
            while(l < r){
                int key = -(nums[l] + nums[r]);
                if(nums[i] > key){
                    r--;
                }else if(nums[i] < key){
                    l++;
                }else{
                    temp[0] = nums[i];
                    temp[1] = nums[l];
                    temp[2] = nums[r];
                    ans.push_back(temp);   
                    while(nums[r] == nums[--r]);
                    while(nums[l] == nums[++l]);
                }
            }
        }
        return ans;
    }
    
    
    
    
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
    vector<vector<int>> threeSum1(vector<int>& n) {
        if(n.size() < 3){
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;
        unordered_map<int, int> mMap; 
        Trie* root = new Trie();
        for(int i = 0; i < n.size(); i++){
            mMap[n[i]] = min(mMap.find(n[i]) == mMap.end() ? 1 : mMap[n[i]] + 1, 3);
        }
        vector<int> nums;
        for(auto& it : mMap){
            for(int i = 0 ; i < it.second ; i++){
                nums.push_back(it.first);
            }
        }
        sort(nums.begin(), nums.end());
        
        vector<int> temp(3,0);
        for(int i = 0; i < nums.size()-2; i++){
            mMap[nums[i]] -= 1;
            for(int j = i + 1; j < nums.size()-1; j++){
                int key = -nums[i] - nums[j];
                if(mMap.find(key) != mMap.end() && mMap[key] > (nums[j] == key ? 1 : 0)){
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = key;
                    sort(temp.begin(), temp.end());
                    if(!root -> hasNext(temp, 0)){
                        ans.push_back(temp);   
                        root -> addNode(temp, 0);
                    }
                }
            }
        }
        return ans;
    }
};
