class Solution {
public:
    class TrieNode{
        public:
            unordered_map<char, TrieNode*> mMap;
            bool hasEnd = false;
            
            void build(string s, int i){
                if(i == s.length()){
                    hasEnd = true;
                    return;
                }
                
                if(!mMap[s[i]]){
                    mMap[s[i]] = new TrieNode();
                }
                mMap[s[i]] -> build(s,i+1);    
            }
        
            string getString(string s, int i){
                if(hasEnd){
                    return s.substr (0,i);
                }
                if(i == s.length()){
                    return s;
                }
                if(mMap[s[i]]){
                    return mMap[s[i]] -> getString(s, i+1);    
                }else{
                    return s;
                }
            }
        
    };
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* root = new TrieNode();
        for(string &it : dict){
            root -> build(it, 0);
        }
        int s = 0, cur = 0;
        string ans = "";
        while(cur < sentence.length()){
            if(sentence[cur] == ' '){
                ans += root -> getString(sentence.substr(s,cur-s),0) + ' ';
                s = cur+1;
            }
            cur++;
        }
        ans += root -> getString(sentence.substr(s,cur-s),0);
        return ans;
    }
};
