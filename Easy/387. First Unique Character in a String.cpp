class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++){
            bool flag =true;
            for(int j=0;j<s.size();j++){
                if(s[i] == s[j] && j!=i){
                    flag = false;
                    break;
                }
            }
            if(flag)return i;
        }
        
        return -1;
    }
};
