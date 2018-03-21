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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> ans;
        int height = getHeight(root,0);
        int width = (1 << height) -1 ;
        ans.resize(height, vector<string>(width,""));
        print(ans, root, 0, 0, width-1);
        return ans;
    }
    int getHeight(TreeNode* root , int height){
        if(root == nullptr){
            return height;
        }
        return max(getHeight(root -> left, height+1), getHeight(root -> right, height+1));
    }
    void print(vector<vector<string>>& temp, TreeNode* root, int level, int start, int end){
        if(root == nullptr)return;
        int index = start + ((end - start) >> 1);
        temp[level][ index ] = to_string(root -> val);
        print(temp, root -> left, level+1, start, index-1);
        print(temp, root -> right, level+1, index +1, end);
    }
};
