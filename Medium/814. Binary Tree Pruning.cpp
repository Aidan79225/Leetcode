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
    TreeNode* pruneTree(TreeNode* root) {
        hasOne(root);
        return root;
    }
    bool hasOne(TreeNode* root){
        bool l = false;
        bool r = false;
        if(root -> left){
            l = hasOne(root -> left);
            if(!l) root -> left = nullptr;
        }
        if(root -> right){
            r = hasOne(root -> right);
            if(!r) root -> right = nullptr;
        }
        return root -> val || l || r;
    }
};
