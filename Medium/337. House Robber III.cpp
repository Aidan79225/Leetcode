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
        return mRob(root).first;
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
    pair<int, int> mRob(TreeNode* root){
        pair<int, int> dp = make_pair(0,0);
        if(root){
            pair<int, int> left = mRob(root->left);
            pair<int, int> right = mRob(root->right);
            dp.second = left.first + right.first;
            dp.first = max(dp.second ,left.second + right.second + root->val);
        }
        return dp;
    }
    
};


