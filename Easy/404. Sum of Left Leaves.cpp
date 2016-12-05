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
    int sumOfLeftLeaves(TreeNode* root,bool isLeft) {
        int left=0,right=0;
        if(root == nullptr)return 0;
        if(root->left == nullptr && root->right == nullptr){
            return isLeft ? root->val : 0;
        }
        if(root -> left != nullptr){
            left = sumOfLeftLeaves(root ->left , true);
        }
        if(root -> right != nullptr){
            right = sumOfLeftLeaves(root ->right , false);
        }
        return left + right;
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root,false);
    }
};
