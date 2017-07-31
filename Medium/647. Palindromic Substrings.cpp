class Solution {
public:
    int countSubstrings(string s) {
        if(s == "") return 0;
        int count = 1;
        for(int i =1; i< s.size(); i++) {
            count += countPalindrom(s, i, i);
            count += countPalindrom(s, i-1, i);
        }
        return count;
    }
    
    int countPalindrom(string& s, int start, int end) {
        int count = 0;
        for(int i =0; start >=0 && end <s.size(); i++){
            if(s[start] != s[end]) break;
            count++;
            start--;
            end++;
        }
        return count;
    }
    int countSubstrings2(string s) {
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++ ){
            for(int j = i ; j < s.length() ; j++ ){
                if(checkP(s,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
    bool checkP(string s, int h, int t){
        if( t-h == 0)return true;
        if( t-h < 0)return false;
        int mid = (t+h) / 2 + 1;
        for(int i = h,j = t ; i<mid ; i++,j--){
            if(s[i] != s[j])return false;
        }
        return true;
    }
};
