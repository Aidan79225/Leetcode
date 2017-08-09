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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums,0,nums.size()-1);
    }
    TreeNode* constructTree(vector<int>& nums,int left,int right) {
        if(left > right)return nullptr;
        int maxIndex = left;
        int max = nums[maxIndex];
        for(int i = left+1 ; i <= right;i++){
            if(nums[i] > max){
                max = nums[i];
                maxIndex = i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root -> left = constructTree(nums,left,maxIndex-1);
        root -> right = constructTree(nums,maxIndex+1,right);
        
        return root;
    }
};
