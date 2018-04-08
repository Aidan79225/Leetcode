class MagicDictionary {
public:
    
    class Trie{
        public:
            Trie(){};
            unordered_map<char,Trie*> mMap;
            bool isEnd = false;
            void insert(string& s, int i){
                if(i == s.length()){
                    isEnd = true;
                    return;
                }
                if(mMap.find(s[i]) == mMap.end()){
                    Trie* t = new Trie();
                    mMap[s[i]] = t;
                }
                mMap[s[i]] -> insert(s,i+1);
            }
            bool find(bool needOne, string& word, int i){
                if(i == word.length()){
                    return !needOne && isEnd;
                }
                if(needOne){
                    for(auto& it : mMap){
                        if(it.second != nullptr && it.second -> find(it.first == word[i], word, i+1)){
                            return true;
                        }
                    }
                    return false;
                }else{
                    return mMap[word[i]] != nullptr && mMap[word[i]] -> find(false, word, i+1);
                }
            }
        
    };
    Trie* root;
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto& it : dict){
            root -> insert(it,0);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return root -> find(true, word, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
