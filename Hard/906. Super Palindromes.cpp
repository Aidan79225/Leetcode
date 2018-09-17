class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long l = stol(L);
        long r = stol(R);
        int count = 0;
        for(long i = 0 ; i <= 34000; i++){
            long v = createPalindrome(i);
            if(v*v > r) break;
            for(int m = -1; m < 10; m++){
                v = createPalindrome(i, m);
                if(checkPalindrome(v*v, l, r)){
                    count++;
                }    
            }
        }
        return count;   
    }
    inline long createPalindrome(long i, int mid=-1){
        long ans = i;
        if(mid != -1){
            ans = ans * 10 + mid;
        }
        while(i){
            ans = ans * 10 + i % 10;
            i /= 10;
        }
        return ans;
    }
    inline bool checkPalindrome(long s, long l ,long r){
        if(s < l || s > r){
            return false;
        }
        long t = 0;
        long n = s;
        while(n){
            t = t * 10 + n % 10;
            n /= 10;
        }
        return s == t;
    }
    
};
