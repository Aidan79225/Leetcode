class Solution {
public:
    int findKthNumber(int n, int k) {
        long long base = 1;
        long long count = 0;
        k--;
        while(k > 0){
            count = getCount(base,n);
            if(count <= k){
                base++;
                k -= count;  
            }else{
                base = base*10;
                k--;
            }    
        }
        return base;
    }
    long long getCount(long long base, long long n){ 
        long long count = 0;
        long long mMax = base + 1;
        long long mMin = base;
        while(mMin <= n){
            count += min(n+1, mMax) - mMin ;
            if(mMax >= n +1)break;
            mMax *= 10;
            mMin *= 10;
        }
        return count;
    }
};
