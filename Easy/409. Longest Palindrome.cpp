class Solution {
public:
    int count[52] = {0};
    void counting(char c){
        if(c - 'A' < 26){
            count[c - 'A']++;
        }else if(c - 'a' < 26){
            count[c - 'a' + 26]++;
        }
    }
    int longestPalindrome(string s) {
        int ans = 0;
        bool hasOdd = false;
        for(int i = 0 ; i<s.size() ; i++){
            counting(s[i]);
        }
        for(int i=0 ; i<52 ; i++){
            if((count[i] & 0b1) == 1){
                hasOdd = true;
                ans += count[i]-1;
            }else{
                ans += count[i];
            }
        }
        return ans + (hasOdd ? 1:0);
    }
};
