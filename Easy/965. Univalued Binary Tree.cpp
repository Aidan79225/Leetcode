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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isUnivalTree(root->val, root);
    }
    
    bool isUnivalTree(int v, TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return root->val == v && isUnivalTree(v, root->left) && isUnivalTree(v, root->right);
    }
};
