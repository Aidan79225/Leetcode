class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int count =0;
        while(count < 31){
            if(n & 0b1)ans += 1;
            n = n>>1;
            ans = ans << 1;
            count ++;
        }
        if(n & 0b1)ans += 1;
        return ans;
        
    }
};
