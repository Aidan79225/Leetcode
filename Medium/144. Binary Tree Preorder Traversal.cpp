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
    vector<int> ans;
    void preorder(TreeNode* root) {
        if(root == NULL)return;
        ans.push_back(root ->val);
        preorder(root -> left);
        preorder(root -> right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};
