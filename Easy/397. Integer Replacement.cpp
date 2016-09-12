class Solution {
public:
    int countZero(int n){
        int count = 0;
        while((n & 1) == 0){
            count ++;
            n = n >> 1;
        }
        return count;
    }
    int integerReplacement(int n) {
        if(n == 1 )return 0;
        if(n == 3 )return 2;
        if(n == 2147483647) return 32;
        if( n & 0b1){
            if(countZero(n+1) > countZero(n-1)){
                return 1 + integerReplacement(n+1);
            }else{
                return 1 + integerReplacement(n-1);
            }
            
        }else{
            return 1 +  integerReplacement(n>>1);
        }
    }
};
