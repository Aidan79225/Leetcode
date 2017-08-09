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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        bfs(ans,root,0);
        return ans;
    }
    void bfs(vector<int>& ans,TreeNode* root , int level){
        if(root == nullptr)return;
        
        if(ans.size()<level+1){
            ans.resize(level+1);
            ans[level] = root -> val;
        }else if(ans[level] < root -> val){
            ans[level] = root -> val;
        }
        
        bfs(ans,root->left,level+1);
        bfs(ans,root->right,level+1);
    }
};
