class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> temp(n,0);
        int index = 0;
        int s = 1;
        bool mSwitch = true;
        int t = k+1;
        while(k >= 0){
            temp[index] = s;
            s += (mSwitch ? k : -k);
            k--;
            index++;
            mSwitch = !mSwitch;
        }
        while(index < n){
            temp[index] = ++t;
            index++;
        }
        return temp;
    }
};
