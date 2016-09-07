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
    bool trval(TreeNode* left,TreeNode* right){
        if(left == NULL){
            if(right == NULL){
                return true;
            }else{
                return false;
            }
        }else{
            if(right == NULL){
                return false;
            }
        }
        
        if(left -> val == right -> val )
            return trval(left -> right , right -> left) & trval(left -> left, right ->right);
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL )return true;
        return trval(root->left,root->right);
    }
};
