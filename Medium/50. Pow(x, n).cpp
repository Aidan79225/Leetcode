class Solution {
public:
    double myPow(double x, int n) {
        double temp =x,ans=1; 
        int i,count=n;
        if(n>0){
            while(1){
            temp =x;
            for(i =1;i<=count && i<1073741823;i=i<<1){
                if((i<<1)<=count)
                    temp *=temp;
            }
            i=i>>1;
            ans *=temp;
            count-=i;
            if(count<=0)break;
            }
        }else if(n<0){
            if(n == -2147483648){
                ans /= x;
                n++;
            }
            count = -n;
            while(1){
                temp =x;
                for(i =1;i<=count && i<1073741823;i=i<<1){
                    if((i<<1)<=count)
                        temp *=temp;
                }
                i=i>>1;
                ans /=temp;
                count-=i;
                if(count<=0)break;
            }
        }
        return ans;
    }
};
