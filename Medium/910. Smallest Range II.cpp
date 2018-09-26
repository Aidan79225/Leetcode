class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int size = A.size();
        int mMax = A[size - 1];
        int mMin = A[0];
        int ans = mMax - mMin;
        for (int i = 0; i < size - 1; ++i) {
            mMax = max(mMax, A[i] + 2 * K);
            mMin = min(A[i + 1], A[0] + 2 * K);
            ans = min(ans, mMax - mMin);
        }
        return ans;
    }
};
