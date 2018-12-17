class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int w = A[0].size();
        int ans = 0;
        int index = 0;
        vector<bool> needCheck(n-1, true);
        while (index < w) {
            bool updateCheck = false;
            bool getAns = true;
            for (int i = 0; i < n - 1; i++) {
                if (needCheck[i]) {
                    if (A[i][index] == A[i+1][index]) {
                        updateCheck = true;
                        getAns = false;
                    } else if(A[i][index] > A[i+1][index]) {
                        ans++;
                        getAns = false;
                        updateCheck = false;
                        break;
                    }
                }
            }
            
            if (updateCheck) {
                for (int i = 0; i < n-1; i++) {
                    needCheck[i] = needCheck[i] && !(A[i][index] < A[i+1][index]);
                }
            }
            
            if (getAns) {
                return ans;
            }
            index++;
            
            
        }
        
        return ans;
    }

    
};
