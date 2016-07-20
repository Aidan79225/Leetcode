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
    int depth = 0;
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left &&  root->right) return min(minDepth(root->left), minDepth(root->right)) + 1;
        return max(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
