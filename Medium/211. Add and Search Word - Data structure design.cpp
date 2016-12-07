class WordDictionary {
    struct TrieNode{
        TrieNode* l[26];
        int n;
        int index;
        TrieNode(){
            memset(l, 0, sizeof(TrieNode*) * 26);
            n = 0;
            index =0;
        }
    } *root = new TrieNode();
public:
    vector<string> strs;
    bool first = true;
    vector<TrieNode*> nodeStack;
    int index =0;
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        for (int i =0; i< word.size(); i++){
            int temp = word[i] - 'a';
            if (!p->l[temp]) p->l[temp] = new TrieNode();
            p = p->l[temp];
        }
        p->n++;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode* p = root;
        
        return dfs(word,0,p);
    }
    bool dfs(string word,int i,TrieNode* cur){
         if (!cur) return false;
        if (word.size() == i) { return cur->n > 0; }
        if (word[i] != '.') {
            int temp = word[i] - 'a';
            return dfs(word, i + 1, cur->l[temp]);
        } else {
            for (int k = 0; k < 26; ++k) {
                if (cur->l[k] && dfs(word, i + 1, cur->l[k])) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
