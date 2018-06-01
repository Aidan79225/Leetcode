class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left=1, right = m*n, mid;
        while(left <= right){
            mid = left + (right-left)/2;
            int count=0, j=n;
            for(int i=1; i<=m; i++){
                while(j >= 1 && i*j > mid) j--;
                count += j;
            }
            if(count < k)left = mid+1;
            else right = mid - 1;
        }
        return left;
    }
};
