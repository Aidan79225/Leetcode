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
    vector<TreeNode*> nodeStack;
    int indexStack =0;
    vector<int> ans;
    void push(TreeNode* cur){
        if(nodeStack.size() == indexStack){
            nodeStack.push_back(cur);
        }else{
            nodeStack[indexStack] = cur;
        }
        indexStack++;
    }
    TreeNode* pop(){
        indexStack--;
        if(indexStack < 0)return nullptr;
        TreeNode* ans = nodeStack[indexStack];
        nodeStack[indexStack] = nullptr;
        return ans;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur;
        cur = root;
        while(cur != nullptr){
            if(cur -> left != nullptr){
                TreeNode* left = cur -> left;
                cur ->left = nullptr;
                push(cur);
                cur = left;
            }else if(cur -> right != nullptr){
                TreeNode* right = cur -> right;
                cur ->right = nullptr;
                push(cur);
                cur = right;
            }else{
                ans.push_back(cur -> val);
                cur = pop();
            }
        }
        return ans;
    }
};
