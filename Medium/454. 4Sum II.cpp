class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        unordered_map<int,int> mapCD;
        for(int k = 0; k<C.size();k++){
            for(int l = 0; l<D.size();l++){
                int key = C[k]+D[l];
                    mapCD[key]++;
            }
        }
        for(int i = 0; i<A.size();i++){
            for(int j = 0; j<B.size();j++){
                int key = -(A[i] + B[j]);
                    count += mapCD[key];
            }   
        }
        return count;
    }
};
