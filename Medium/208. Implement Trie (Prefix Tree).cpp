class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* l[26];
    int n;
    TrieNode() {
        memset(l, 0, sizeof(TrieNode*) * 26);
        n = 0;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (int i =0; i< word.size(); i++){
            int temp = word[i] - 'a';
            if (!p->l[temp]) p->l[temp] = new TrieNode();
            p = p->l[temp];
        }
        p->n++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for (int i =0; i<word.size(); i++){
            int temp = word[i] - 'a';
            if (!p->l[temp]) return false;
            p = p->l[temp];
        }
        return p->n > 0;
    }
    

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i =0; i<prefix.size(); i++){
            int temp = prefix[i] - 'a';
            if (!p->l[temp]) return false;
            p = p->l[temp];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
