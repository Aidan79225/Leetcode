class Solution {
public:
    bool check2(string p,string s){
        int counts=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ')counts++;
        }
        return p.size()  == (counts + 1);
    }
    bool check(string s,string p){
        if(s.size() != p.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i] != p[i])return false;
        }
        return true;
    }
    int getString(int position,string str){
        int i = 0;
        while(str[position] != ' ' && position < str.size()){
            i++;
            position++;
        }
        return i;
    }
    bool wordPattern(string pattern, string str) {
        int p=0,s=0,nextS=0, size = str.size(), psize = pattern.size();
        if(!check2(pattern,str)){
            return false;
        }
        map< string , char> map2;
        map<char, string> map;
        
        nextS = getString(s,str);
        while(nextS<size && p<psize){
            string temp = str.substr(s,nextS);
            if(map.find(pattern[p]) == map.end() && map2.find(temp) == map2.end()){
                map[pattern[p]] = temp;
                map2[temp] = pattern[p];
            }else if(map.find(pattern[p]) != map.end()){
                if(!check(map[pattern[p]] , temp) ){
                    return false;
                }
            }else if(map2.find(temp) != map2.end()){
                if(map2[temp] != pattern[p]){
                    return false;
                }
            }
            s += nextS+1;
            nextS = getString(s,str);
            p++;
        }
        
        return true;
    }
};
