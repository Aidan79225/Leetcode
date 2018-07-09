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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<int> dp(501, -1);
        int l = getDepth(root -> left, dp);
        int r = getDepth(root -> right, dp);
        if(l > r){
            return subtreeWithAllDeepest(root -> left);    
        }else if(l < r){
            return subtreeWithAllDeepest(root->right);
        }else{
            return root;
        }   
    }
    int getDepth(TreeNode* root, vector<int>& dp){
        if(root == nullptr)return 0;
        if(dp[root -> val] != -1)return dp[root -> val];
        int l = getDepth(root -> left, dp);
        int r = getDepth(root -> right, dp);
        dp[root -> val] = max(l, r) + 1;
        return dp[root -> val];
    }
};
