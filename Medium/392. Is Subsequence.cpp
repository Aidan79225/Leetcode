class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size = t.size();
        int index =0,ssize = s.size();
        if(ssize > size)return false;
        int i=0;
        for(index = 0;index<ssize;index++){
            while(i < size && s[index] != t[i])i++;
            if(i == size)return false;
            else i++;
        }
        return true;
        
    }
};
