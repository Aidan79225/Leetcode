class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        int mSqrt = sqrt(num)+1;
        for(int i = 2; i < mSqrt ; i++){
            if(num % i == 0){
                sum += i + num / i ;
            }
        }
        return sum == num && num != 1;
    }
};
