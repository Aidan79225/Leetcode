class Solution {
public:
    int integerBreak(int n) {
        int ans = 1;
        if(n == 2)return 1;
        else if(n == 3)return 2;
        switch(n % 3){
            case 0:
                break;
            case 1:
                ans *= 4;
                n -= 4;
                break;
            case 2:
                ans *=2;
                n -= 2;
                break;
        }
        while(n > 0){
            ans *=3;
            n -= 3;
        }
        return ans;
    }
};
