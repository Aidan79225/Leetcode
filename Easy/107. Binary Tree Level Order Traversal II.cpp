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
    void ansFunc(vector<vector<int>>& ans , int level,TreeNode* root){
        if(root == NULL)return;
        if(ans.size() <= level){
            vector<int> g;
            ans.push_back(g);
        }
        
        ansFunc(ans,level+1,root->left);
        ansFunc(ans,level+1,root->right);
        ans[level].push_back(root -> val);
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        ansFunc(ans,0,root);
        int n = ans.size();
        for(int i =0;i<n/2;i++){
            vector<int> temp = ans[i];
            ans[i] = ans[n-i-1];
            ans[n-i-1] = temp;
        }
        return ans;
    }
};
