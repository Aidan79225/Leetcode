class Solution {
public:
    bool isV(char c){
        switch(c){
            case 'a':case 'e':case 'i':case 'o':case 'u':case 'A':case 'E':case 'I':case 'O':case 'U':return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        if(s.size() == 0 )return s;
        int i=0,j=s.size()-1;
        while(i<j){
            while(!isV(s[i]) && i<=j)i++;
            while(!isV(s[j]) && j>=0)j--;
            if(i>=j)break;
            char t = s[i];
            s[i]=s[j];
            s[j]=t;
            i++;
            j--;
        }
        return s;
        
    }
};
