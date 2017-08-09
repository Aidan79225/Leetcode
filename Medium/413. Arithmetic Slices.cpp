class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = 0;
        int cur = 0;
        for(int i = 2 ; i < A.size(); i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                cur++;
                count += cur;
            }else{
                cur = 0;
            }
        }   
        return count;
    }
};
