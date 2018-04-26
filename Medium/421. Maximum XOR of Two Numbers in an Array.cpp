class Solution {
public:
    class TrieNode{
        public:
            TrieNode* left;
            TrieNode* right;   
    };
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int ans = 0;
        for(int n : nums)ans = max(ans, build(root,n));
        return ans;
        
    }
    
    int build(TrieNode* p, int num){
        TrieNode* q = p;
        int ans = 0, mask = 1<<30;
        for (int i = 30; i >= 0; i--) {
            ans <<= 1;
            if (num&mask) {
                //build a trie
                if (p->right == NULL)  p->right = new TrieNode();
                p = p->right;
                //get xor value on the fly
                if (q->left) {
                    ans++;
                    q = q->left;
                }
                else 
                    q = q->right;
            }
            else {
                if (p->left == NULL)  p->left = new TrieNode();
                p = p->left;
                if (q->right) {
                    ans++;
                    q = q->right;
                }
                else 
                    q = q->left;
            }
            mask >>= 1;
        }
        return ans;
        
    }
    
};
