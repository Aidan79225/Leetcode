class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        int count[2];
        for(int c = 0 ; c < 31; c++){
            count[0] = 0;
            count[1] = 0;
            for(int& i : nums){
                count[i & 0b1]++;
                i = i >> 1;   
            }    
            ans += count[0] *count[1];
        }
        return ans;
    }
    int totalHammingDistance1(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        unordered_map<int,int> mMap;
        for(int i = 0 ; i < size-1 ; i++){
            for(int j = i + 1 ; j < size ; j++){
                int key = nums[i] ^ nums[j];
                if(mMap.find(key) == mMap.end()){
                    int distance = getDistance(nums[i] ^ nums[j]);
                    mMap[key] = distance;
                    ans += distance;   
                }else{
                    ans += mMap[key];   
                }
            }
        }
        return ans;
    }
    int getDistance(int x){
        int count = 0;
        for(int i = 0,mask = 1 ; i < 31 ;i++, mask = mask<<1){
            if(x & mask){
                count++;
            }
        }
        return count;
    }
};
