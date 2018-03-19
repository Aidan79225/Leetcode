class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> mMap(26);
        for(auto& it : licensePlate){
            if(!isDig(it)){
                mMap[toLow(it)]++;       
            }
        }
        string ans = "";
        for(auto& it : words){
            if(check(mMap, it)){
                if(ans.size() == 0 || ans.size() > it.size()){
                    ans = it;
                }
            }
        }
        return ans;
    }
    bool check(vector<int> mMap, string word){
        vector<int> t(26);
        for(auto& it : word){
            if(!isDig(it)){
                t[toLow(it)]++;   
            }
        }
        for(int i = 0 ; i < mMap.size() ; i++){
            if(mMap[i] > t[i]){
                return false;
            }
        }
        return true;
    }
    bool isDig(char c){
        return c >= '0' && c <= '9';
    }
    int toLow(char c){
        if(c >= 'A' && c <= 'Z'){
            return c - 'A';
        }else{
            return c - 'a';   
        }
    }
    
    
};
