/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        int rootPass = getCoin(root, ans);
        return ans + rootPass;
    }
    
    int getCoin(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return 0;
        }
        int l = getCoin(root->left, ans);
        int r = getCoin(root->right, ans);
        ans += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
    
};
