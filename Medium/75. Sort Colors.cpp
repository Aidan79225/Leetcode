class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size(), i = 0; //用left記錄最靠右邊的0,用right記錄最靠左邊的2
        while(i < right){
            if(nums[i] == 0 && i != ++left)
                swap(nums[left], nums[i]);         //搬動0到該在的地方
            else if(nums[i] == 2 && i != --right)
                swap(nums[right], nums[i]);        //搬動2到該在的地方
            else
                i++;                               //遇到1不管他 看下個東西是啥
        }      
    }
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors1(vector<int>& nums) {
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
