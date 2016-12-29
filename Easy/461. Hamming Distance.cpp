// 比對第一個bit 不一樣就+1 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x != 0 || y != 0){
            if((x & 0b1) != (y & 0b1))ans++;
            x = (x>>1);
            y = (y>>1);
        }
        return ans;
    }
};
