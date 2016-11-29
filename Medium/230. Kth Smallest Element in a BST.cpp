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
    void TreeWalker(vector<int> &ans , TreeNode* root,int k){
        if(ans.size() == k)return;
        if(root == nullptr)return;
        TreeWalker(ans,root->left,k);
        ans.push_back(root -> val);
        TreeWalker(ans,root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        TreeWalker(ans,root,k);
        return ans[k-1];
    }
};
