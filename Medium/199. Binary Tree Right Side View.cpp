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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int level, vector<int>& ans){
        if(root == nullptr){
            return;
        }
        if(ans.size() == level){
            ans.push_back(root -> val);
        }
        dfs(root -> right, level+1, ans);
        dfs(root -> left, level+1, ans);
    }
    
};
