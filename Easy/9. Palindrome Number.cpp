class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        
        int div=1;
        while(x / div != 0 && div != 1000000000){
            div *= 10;
        }
        if(div != 1000000000)div /= 10;
        while(x !=  0){
            int l = x % 10;
            int r = x / div ;
            if(l != r)return false;
            x = x - r * div;
            x /= 10;
            div /= 100;
        }
        return true;
    }
};
