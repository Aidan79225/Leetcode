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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> mQ;
        mQ.push(root);
        while(!mQ.empty()) {
            TreeNode* t = mQ.front();
            mQ.pop();
            if (t == nullptr) {
                break;
            }
            mQ.push(t -> left);
            mQ.push(t -> right);   
        }
        while(!mQ.empty() && mQ.front() == nullptr){
            mQ.pop();
        }
        
        return mQ.empty();
    }

};
