class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            sort(pairs.begin(), pairs.end(),[&](vector<int> a, vector<int> b){
                return a[1] < b[1];
            });
            int stackT = 0;
            for(auto& it : pairs){
                if( pairs[stackT][1] < it[0]){
                    stackT++;
                    swap(pairs[stackT], it);
                }
            }
            return stackT+1;
        }
    
};
