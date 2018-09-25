class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mMax = 0;
        int mMin = INT_MAX;
        for(int i : A){
            if(mMax < i){
                mMax = i;
            }
            if(mMin > i){
                mMin = i;
            }
        }
        return max(0, mMax - mMin - 2*K);
    }
};
