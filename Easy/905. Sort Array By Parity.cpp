class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int oddIndex = A.size()-1;
        int evenIndex = 0;
        while(oddIndex > evenIndex){
            if(A[evenIndex] & 1){
                swap(A[evenIndex], A[oddIndex]);
                oddIndex--;
            }else{
                evenIndex++;
            }
        }
        return A;
    }
};
