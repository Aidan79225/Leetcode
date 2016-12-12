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
    static TreeNode* saveNode(int left,int right,vector<int>& nums){
        int mid = (left+right)/2;
        if(right - left ==1){
            TreeNode* ans = new TreeNode(nums[right]);    
            ans -> left = new TreeNode(nums[left]);
        }
        if(right <= left)return nullptr;
        
        
        TreeNode* ans = new TreeNode(nums[mid]);
        ans -> left = saveNode(left,mid,nums);
        ans -> right = saveNode(mid+1,right,nums);
        
        return ans;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = saveNode(0,nums.size(),nums);
        return ans;
    }
};
