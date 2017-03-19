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
    int rob(TreeNode* root) {
        return rob(root,true,0);
    }
    int rob(TreeNode* root, bool can, int now){
        if(root == nullptr)return now;
        int steal = 0;
        int notSteal = 0;
        if(can){
            steal = rob(root -> left, false, 0 ) +  rob(root -> right, false, 0 ) +  root-> val + now;
        }
        notSteal = rob(root -> left, true, 0) +  rob(root -> right, true, 0) + now;
        return steal > notSteal ? steal : notSteal;
    }
};
