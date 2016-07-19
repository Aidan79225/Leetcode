class Solution {
public:
    int reverse(int x) {
        bool negive = false;
        int ans=0;
        if(x<0){
            negive = true;
            x = -x;
        }
        for(;x>0;x/=10){
            if(ans>214748364)
                return 0;
            else if(ans == 214748364){
                if(!negive && x%10>7)return 0;
                if(negive && x%10>8)return 0;
            }
            ans*=10;
            ans+=x%10;
            
        }
        return negive?-ans:ans;
    }
};
