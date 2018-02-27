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
    int countNodes(TreeNode* root) {
        if(root == nullptr)return 0;
        TreeNode* temp = root;
        int leftH = leftmostHeight(temp);
        int l = 0;
        int r = (1<<(leftH-1))-1;
        int tempLeftH= 0;
        while(l < r){
            tempLeftH++;
            int key = leftmostHeight(temp -> right);
            int mid = l + (r-l)/2;
            if(key + tempLeftH < leftH){
                temp = temp -> left;
                r = mid ;
            }else{
                temp = temp -> right;
                l = mid+1;
            }
            
        }        
        return (1 << (leftH-1))  + l;
    }
    int leftmostHeight(TreeNode* temp){
        int left = 0;
        while(temp != nullptr){
            temp = temp -> left;
            left++;
        }
        return left;
    }
};
