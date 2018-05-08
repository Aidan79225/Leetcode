class Solution {
public:
    int magicalString(int n) {
        if(n == 0)return 0;
        if(n <= 3)return 1;
        int count = 0;
        int ans = 0;
        int p1 = 2;
        int p2 = 2;
        vector<int> t(n + 2,0);
        t[0] = 1;
        t[1] = 2;
        t[2] = 2;
        while(p1 < n){
            count = t[p1] ^ 3;
            for(int i = 0 ; i < t[p2] ; i++){
                t[p1+1] = count;
                p1++;
            }
            p2++;
        }
        for(int i=0; i < n; i++){
            ans += (t[i] & 0b1);
        }
        return ans;
    }
};
