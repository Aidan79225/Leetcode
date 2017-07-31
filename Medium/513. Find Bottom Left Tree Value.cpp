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
    int ans = 0;
    int findBottomLeftValue(TreeNode* root) {
        unordered_map<int,TreeNode*> mMap;
        push(mMap,0,root);
        return mMap[ans] -> val;
    }
    void push(unordered_map<int,TreeNode*>& mMap,int level, TreeNode* root){
        if(root == nullptr)return;
        if(mMap.find(level) == mMap.end()){
            mMap[level] = root;
            if(level > ans) ans = level;
        }
        push(mMap, level+1, root -> left);
        push(mMap, level+1, root -> right);
    }
};
