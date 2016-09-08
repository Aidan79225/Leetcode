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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)return false;
        int ans = sum-root->val;
        if(ans == 0 && root->left == NULL && root->right == NULL)return true;
        return hasPathSum(root -> left , ans) || hasPathSum(root -> right , ans);
    }
};
