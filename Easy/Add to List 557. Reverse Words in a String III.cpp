class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        while(start < s.length()){
            int end = start;
            while( end < s.length() && s[end] != ' '  ){
                end++;
            }
            reverse(s,start,end-1);
            start = end+1;
        }
        
        return s;
    }
    void reverse(string &s, int start, int end){
        int mid = start + (end - start) / 2 ;
        for(int i = start, j = end ; i <= mid ; i++,j-- ){
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
    }
};
