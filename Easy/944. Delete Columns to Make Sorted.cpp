class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        int ans = 0;
        for(int c = 0; c < m; c++){
            for(int i = 1; i < n; i++){
                if(A[i][c] - A[i-1][c] < 0){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
