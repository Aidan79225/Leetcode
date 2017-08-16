class Solution {
public:
    int newInteger(int n) {
        int res = 0, mod = 1;
        while (n > 0) {
            res += (n % 9) * mod;
            n /= 9;
            mod *= 10;
        }
        return res;
    }

    int newInteger2(int n) {
        int ans = 0;
        int mod[9] = {9,81,729,6561,59049,531441,4782969,43046721,387420489};
        // int sub =0;
        // for(int i = 10,j=0 ; i <= 1000000000 ; i *= 10,j++){
        //     sub = sub*9 + i/10;
        //     mod[j] = i - sub;
        //     cout<<"index:"<<i<<", num:"<< i - sub<<endl;
        // }
        for(int i = 1000000000,j=8 ; j>= 0 ; i /= 10,j--){
            int temp =  n / mod[j];
            if(temp > 0){
                ans += i * temp;
                n = n % mod[j];   
                cout<<ans<<endl;
            }
        }
        return ans + n;
    }
};
