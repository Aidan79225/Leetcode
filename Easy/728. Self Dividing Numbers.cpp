class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left ; i <= right ; i++){
            if(check(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool check(int n){
        int temp = n;
        while(temp > 0){
            int mod = temp % 10;
            if(mod != 0 && n % mod == 0){
                temp /= 10;
            }else{
                return false;
            }
        }
        return true;
    }
};
