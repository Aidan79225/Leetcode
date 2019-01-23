class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size(), 0);
        
        int start = 0;
        while (A[start] < 0) {
            start++;
        }
        
        int i = start;
        int j = start-1;
        int index = 0;
        
        while (j >= 0 && i < A.size()) {
            if (-A[j] < A[i]) {
                ans[index] = A[j] * A[j];
                j--;
            } else {
                ans[index] = A[i] * A[i];
                i++;
            }
            index++;
        }
        
        while (i < A.size()) {
            ans[index] = A[i] * A[i];
            i++;
            index++;
        }
        
        while (j >= 0) {
            ans[index] = A[j] * A[j];
            j--;
            index++;
        }
              
        return ans;
        
    }
};
