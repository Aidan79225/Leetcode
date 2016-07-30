class Solution {
public:
    int maxnum(int a,int b){
        return a>b?a:b;
    }
    int minnum(int a,int b){
        return a<b?a:b;
    }
    
    
    int payArrayAns(int min,int max,vector<vector<int>>& payArray){
        if(max<=min)return 0;
        if(payArray[min][max] !=0)return payArray[min][max];
        if((max-min)<=1){
            return min;
        }
        else{
            int maxPay=2147483647;
            for(int i=min;i<max;i++){
                int temp = i+ maxnum(payArrayAns(min,i-1,payArray),payArrayAns(i+1,max,payArray));
                maxPay = minnum(maxPay,temp);
            }
            payArray[min][max] = maxPay;
            return maxPay;
        }
    }
    int pay(int min,int max){
        if(max<=min)return 0;
        if((max-min)<=1){
            return min;
        }
        else{
            int maxPay=2147483647;
            for(int i=min;i<max;i++){
                int temp = i+ maxnum(pay(min,i-1),pay(i+1,max));
                maxPay = minnum(maxPay,temp);
            }
            return maxPay;
        }
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> payArray(n + 1, vector<int>(n + 1, 0));
        return payArrayAns(1,n,payArray);
    }
    
};
