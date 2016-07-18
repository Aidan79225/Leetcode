// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int min=0,max=n,mid = (min+max)/2,ans;
        ans = guess(mid);
        while(ans !=0){
            if(ans ==-1){
                max = mid;
            }else if(ans == 1){
                min = mid;
            }
            mid = min + (max-min)/2;
            ans = guess(mid);
            if(max-min < 2)break;
        }
        return guess(max)==0?max:guess(mid)==0?mid:min;
    }
};
