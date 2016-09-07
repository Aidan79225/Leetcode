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
    int depth(TreeNode* root){
        if(root == NULL)return 0;
        int a =1 + depth(root -> left);
        int b =1 + depth(root -> right);
        return a>b ? a : b;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        if(abs(depth(root -> left) - depth(root -> right)) <= 1)return isBalanced(root -> left) & isBalanced(root -> right) ;
        else return false;
    }
};
