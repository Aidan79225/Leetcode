class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> s(26, 0);
        int i = 0;
        for (auto &it : order) {
            s[it - 'a'] = i++;
        }
        for (int i = 1; i < words.size(); i++) {
            if (check(words[i-1], words[i], s)) {
                return false;
            }
        }
        return true;
    }
    
    bool check(string& a, string& b, vector<int>& s){
        for (int i = 0; i < a.size(); i++) {
            if(i >= b.length() ){
                return true;
            } else if (s[a[i] - 'a'] > s[b[i] - 'a']) {
                return true;
            } else if (s[a[i] - 'a'] < s[b[i] - 'a']) {
                return false;
            }
        }
        return false;
    }
};
