class Solution {
public:
    bool hash[128] = {false};
    bool isIn(char c){
        return hash[c];
    }
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2)return s.size();
        int max = 0, cur = 0,head=0;
        for(int i =0;i<s.size();i++){
            if(isIn(s[i])){
                while(s[head] != s[i] && head < i){
                    hash[s[head]] = false;
                    head++;
                }
                if(head < i)head++;
            }else{
                
                hash[s[i]] = true;
            }
            cur = i - head + 1;
            if(max < cur)max = cur;
        }
        return max ;
    }
};
