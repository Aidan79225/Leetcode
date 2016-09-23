class Solution {
public:
    int bulbSwitch(int n) {
        int ans =0;
        int count = 0;
        int interval =2;
        while(count < n){
            ans++;
            count++;
            count += interval;
            interval += 2;
        }
        return ans;
    }
};
