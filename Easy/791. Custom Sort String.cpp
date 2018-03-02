class Solution {
public:
    unordered_map<char,int> index;
    string customSortString(string S, string T) {
        for(int i = 0 ; i < T.size() ; i++){
            index[T[i]] = INT_MAX;
        }
        for(int i = 0 ; i < S.size() ; i++){
            index[S[i]] = i;
        }
        sort(T.begin(),T.end(),[&](const auto& a, const auto& b){
            return index[a] < index[b];
        });
        return T;
    }
};
