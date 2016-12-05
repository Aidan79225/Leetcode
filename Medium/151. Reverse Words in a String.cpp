class Solution {
public:
    void reverseWords(string &s){
        int space = 0;
        while(s[space] ==' '){
            s.erase(s.begin()+space);
        }
        
        for(int i=0; i<s.size()/2; i++){
            char temp = s[i];
            s[i] = s[s.size()-i-1];
            s[s.size()-i-1] = temp;
        }

        int word =1;
        for(int i=0; i<=s.size(); i++){
            if(s[i] == ' ' || s[i] == '\n' || s[i] == '\f' || s[i] == '\0'){
                if(s[i+1] == ' '){
                    s.erase(s.begin() +i);
                    i--;
                    continue;
                }
                word--;
                for(int k=0; k<word/2; k++){
                    char temp = s[i-word+k];
                    s[i-word+k] = s[i-1-k];
                    s[i-1-k] = temp;
                }
                word=0;
            }
            word++;
        }
        int i,j;
        for(i = s.size()-1 ;i>=0;i--){
            if(s[i] !=' ')break;
        }
        for(j=0;j<s.size();j++){
            if(s[j] != ' ')break;
        }
        s=s.substr(j,j-i+1);
        
        
    }
};
