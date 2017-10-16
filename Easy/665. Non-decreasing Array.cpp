class Solution {
public:
    bool checkWorstPossibility(vector<int>& nums) {
        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] < nums[i-1]){
                vector<int> first(nums);
                vector<int> second(nums);
                first.erase(first.begin() + i-1 );
                second.erase(second.begin() + i );
                return checkRealPossibility(first) || checkRealPossibility(second);
            }
        }
        return true;
    }
    
    bool checkRealPossibility(vector<int>& nums) {
        bool isFirst = true;
        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                cnt--;
                if (cnt < 0) return false;
                if (i == 1 || i > 1 && nums[i] > nums[i-2])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
            
        }
        return true;
    }
};
