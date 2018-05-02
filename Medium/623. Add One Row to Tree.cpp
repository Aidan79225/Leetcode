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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root)return root;
        if(d == 1){
            TreeNode* t = new TreeNode(v);
            t -> left = root;
            return t;
        }else if(d == 2){
            TreeNode* l = new TreeNode(v);
            l -> left = root -> left;
            root -> left = l;
            TreeNode* r = new TreeNode(v);
            r -> right = root -> right;
            root -> right = r;
        }else if(d > 2){
            addOneRow(root->left,v,d-1);
            addOneRow(root->right,v,d-1);
        }
        return root;
    }
};
