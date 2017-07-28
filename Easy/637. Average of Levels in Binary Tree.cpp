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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        vector<double> ans;
        while (!Q.empty()){
            int qs = Q.size();
            double sum = 0;
            for (int i = 0; i < qs; ++i){
                TreeNode* node = Q.front();
                Q.pop();
                sum += node->val;
                if (node->left){
                    Q.push(node->left);
                }
                if (node->right){
                    Q.push(node->right);
                }
            }
            ans.push_back(sum / qs);
        }
        return ans;
    }
    
    vector<double> averageOfLevels1(TreeNode* root) {
        vector<double> ans;
        unordered_map<int, pair<int, double>> mMap;
        compute(mMap,root,0);
        for(int i = 0 ; i < mMap.size() ; i++ ){
            ans.push_back((double)mMap[i].second / (double)mMap[i].first);
        }
        return ans;
    }
    void compute(unordered_map<int,pair<int, double>>& mMap, TreeNode* root, int level) {
        if(root == nullptr)return;
        mMap[level].first++;
        mMap[level].second += root->val;
        compute(mMap, root->right , ++level);
        compute(mMap, root-> left, level);
    }
    
};
