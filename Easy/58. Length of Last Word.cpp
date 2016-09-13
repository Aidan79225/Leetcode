class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0,size = s.size() ,i = size-1;
        while(s[i] == ' ' && i>=0){
            i--;
        }
        for(;i>=0;i--){
            if(s[i] == ' ')break;
            count++;
        }
        return count;
    }
};
