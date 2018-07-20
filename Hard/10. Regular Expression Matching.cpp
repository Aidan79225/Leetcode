class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, p, s.length(), p.length());
    }
    
    bool isMatch(string s, string p, int indexS, int indexP) {
        if(indexS == 0 && indexP == 0)return true;
        if(indexP == 0)return false;
        if(indexS == 0){
            while(indexP > 0){
                if(p[indexP-1] != '*'){
                    return false;
                }
                indexP -= 2;
            }
            return indexP == 0;
        }else{
            if(s[indexS-1] == p[indexP-1] || p[indexP-1] == '.'){
                return isMatch(s, p, indexS-1, indexP-1);
            }else{
                if(p[indexP-1] == '*'){
                    if(indexP > 0 && (p[indexP - 2] == s[indexS - 1] || p[indexP - 2] == '.')){
                        if(isMatch(s, p, indexS-1, indexP)){
                            return true;
                        }
                    }
                    return isMatch(s, p ,indexS, indexP-2);
                }else{
                    return false;
                }
            }
            
        }
    }
    
    
    bool isMatch1(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.length() > 1 && p[1] == '*'){
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0]||p[0] == '.') && isMatch(s.substr(1), p));
        }else{
            return !s.empty() && (s[0] == p[0]||p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
};
