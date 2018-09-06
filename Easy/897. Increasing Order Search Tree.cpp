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
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr)return root;
        TreeNode* newRoot = increasingBST(root -> left);
        root -> left = nullptr;
        if(newRoot == nullptr) {
            newRoot = root;   
        }else{
            TreeNode* temp = newRoot;
            while(temp->right != nullptr){
                temp = temp -> right;
            }
            temp -> right = root;
        }
        root -> right = increasingBST(root -> right);
        return newRoot;
    }
};
