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
    void insert(int level,vector<vector<int>>& ans , TreeNode* root){
        if(root == NULL)return;
        if(ans.size()<=level){
            vector<int> temp;
            ans.push_back(temp);
        }
        ans[level].push_back(root->val);
        insert(level+1,ans,root ->left);
        insert(level+1,ans,root ->right);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        insert(0,ans,root);
        return ans;
    }
};
