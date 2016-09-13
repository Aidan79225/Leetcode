class Solution {
public:
    map<int , vector<int>> hash;
    void insert(int index, int num){
        if(hash.find(num) == hash.end() ){
            vector<int> c;
            c.push_back(index);
            hash[num] = c;
        }else{
            hash[num].push_back(index);
        }
    }
    bool check(vector<int> arr,int k){
        int size = arr.size();
        if(size <=1)return false;
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(abs(arr[j]-arr[i]) <= k){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if( k ==0)return false;
        int size = nums.size();
        for(int i =0;i<size;i++){
            insert(i,nums[i]);
        }
        for(map<int,vector<int>>::iterator it = hash.begin(); it != hash.end(); ++it) {
            if(check((*it).second,k))   
                return true;
        }
        return false;
    }
};
