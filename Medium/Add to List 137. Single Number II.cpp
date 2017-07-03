class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int index = 1;
        for(int i =0;i<32;i++){
            int count =0;
            for(int j =0;j<nums.size();j++){
                if(index & nums[j]){
                    count++;
                }
            }
            if(count % 3) ans |= index;
            index = (index << 1);
        }
        return ans;
    }
};
