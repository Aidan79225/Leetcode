class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int ans = 0;
        int mod = 1000000007;
        int size = A.size();
        vector<int> dp(size, 0);
        stack<int> minStack; //store index
        minStack.push(-1);
        for(int i = 0; i < size; i++){
            while(minStack.size() > 1 && A[minStack.top()] > A[i]) minStack.pop();
            dp[i] = (i-minStack.top()) * A[i] + (minStack.size() > 1 ? dp[minStack.top()] : 0);
            minStack.push(i);
        }
        for(int i = 0; i < size; i++){
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
    
    class MinQueue{
        queue<int> mQueue;
    public:
        void insert(int v){
            while(!mQueue.empty() && mQueue.front() > v){
                mQueue.pop();
            }
            mQueue.push(v);
        }
        int getMin(){
            return mQueue.front();
        }
        void pop(){
            mQueue.pop();
        }
    };
    int sumSubarrayMins2(vector<int>& A) {
        int ans = 0;
        int mod = 1000000007;
        for(int i = 0; i < A.size(); i++){
            MinQueue mQueue;
            for(int j = i; j < A.size(); j++){
                mQueue.insert(A[j]);
                ans += mQueue.getMin();
                ans %= mod;
            }
        }
        return ans;
    }
};
