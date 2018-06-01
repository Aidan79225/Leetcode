/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    vector<TreeNode*> mQ;
    unsigned int qIndex = 0;
    string serialize(TreeNode* root) {
        if(root) return to_string(root -> val) + "/" + serialize(root -> left) + serialize(root -> right); 
        else return "#/";
    }
    
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.empty())return nullptr;
        vector<TreeNode*> data;
        int c = 0;
        int len = s.length();
        for(int i = 0 ; i < len ; i++){
            if(s[i] == '/'){
                if(s[c] == '#'){
                    data.push_back(nullptr);
                }else{
                    data.push_back(new TreeNode(stoi(s.substr(c, i-c))));
                }
                c = i+1;
            }
        }
        int index = 0;
        return deserialize(data, index);   
    }
    
    TreeNode* deserialize(vector<TreeNode*>& data,int& index) {
        TreeNode* t = data[index];
        if(t){
            t -> left = deserialize(data, ++index);
            t -> right = deserialize(data, ++index);
        }
        return t;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
