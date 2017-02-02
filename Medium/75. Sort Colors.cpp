class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};           //分別用來記錄0,1,2出現的次數
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int index=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<count[i];j++){
                nums[index] = i;      //根據出現次數調整結果
                index++;
            }
        }
    }
};
