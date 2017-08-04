class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n){return uniquePaths(n,m);}
        long ans = 1;
        long div = 1;
        for(int i = m+n-2,j=n-1 ;j > 0; i--,j--){
            ans *= i;
            div *= j;
        }
        return ans / div;
    }
};
