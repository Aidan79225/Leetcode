class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int size = A.size();
        vector<int> lis(size, 1);
        vector<int> rlis(size, 1);
        int sign = -1;
        for (int i = 0; i < size-1; i++) {
            int cur = A[i]*sign;
            int next = A[i+1]*sign;
            if (cur > next) {
                lis[i+1] = lis[i] + 1;
            } else if (cur < next) {
                rlis[i+1] = rlis[i] + 1;
            }
            sign = -sign;
        }
        
        int ans = 1;
        for (int i = 0; i<size; i++) {
            ans = max(ans, max(lis[i], rlis[i]));
        }

        return ans;
    }
    
    void print(vector<int>& array) {
        for (auto & it : array) {
            cout<<it<<", ";
        }
        cout<<endl;
    }
};
