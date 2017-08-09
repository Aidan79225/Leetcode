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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mMap;
        getTreeSum(root,mMap);
        vector<int> ans;
        int maxF = 0;
         for (auto& x: mMap) {
             if(x.second > maxF)maxF = x.second;
        }
        for (auto& x: mMap) {
             if(x.second == maxF){
                 ans.push_back(x.first);
             }
        }
        return ans;
    }
    int getTreeSum(TreeNode* root,unordered_map<int, int>& mMap){
        if(root == nullptr)return 0;
        int sum = root -> val + getTreeSum(root->left,mMap) + getTreeSum(root->right,mMap);
        mMap[sum]++;
        return sum;
    }
};
