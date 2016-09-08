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
    void reverse(string & s){
        int n = s.size();
        for(int i = 0; i < n/2 ; i++){
            char temp = s[i];
            s[i] = s[n-i-1] ;
            s[n-i-1] = temp ;
        }
    }
    void getPaths(TreeNode* root, string s,vector<string> &ans) {
        if(root == NULL)return;
        string a = "";
        int val = root->val;
        bool nage = val < 0;
        if(val == 0) a += '0';
        if(nage)val = - val;
        while(val != 0 ){
            a += '0' + val % 10;
            val /= 10;
        }
        reverse(a);
        if(nage )s+='-';
        s += a;
        if(root->left ==  NULL ){
            if(root->right == NULL){
                ans.push_back(s);
                return;    
            }else{
                getPaths(root->right , s+"->",ans);
            }
        }else{
            getPaths(root->left , s+"->",ans);
            if(root->right != NULL){
                getPaths(root->right , s+"->",ans);        
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        getPaths(root,"",ans);
        return ans;
    }
};
