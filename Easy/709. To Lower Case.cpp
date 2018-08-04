class Solution {
public:
    string toLowerCase(string str) {
        string ans = "";
        for(char c : str){
            ans += toLowerCase(c);
        }
        return ans;
    }
    char toLowerCase(char c){
        if(c >= 'A' && c <='Z'){
            c = c - 'A' + 'a';
        }
        return c;
    }
};
