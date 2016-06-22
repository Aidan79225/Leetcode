class Solution {
public:
    int mySqrt(int x) {
        int r=x,l=0,mid,temp;
        if(x==1)return 1;
        if(r>46340)r=46341;					//int限制最大2147483647 最大sqrt(x)=46341
        while(r>l){							
            mid = (r+l)/2;					//2分逼近法
            temp =mid*mid;
            if(temp>x){
                r =mid;
            }else if(temp<x){
                l=mid;
            }else
                return mid;
            if(r==l+1)return l;
        }
        return r; 
    }
};
