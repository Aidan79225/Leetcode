/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* cur;
    vector<TreeNode*> nodeStack;
    int index =0;
    int now =0;
    int max =0;
    bool first = true;
    void tralvel(TreeNode *root){
        if(root == nullptr)return;
        tralvel(root -> left);
        max++;
        tralvel(root -> right);
    }
    BSTIterator(TreeNode *root) {
        if(root == nullptr)return;
        tralvel(root);
        cur = root;
        if(cur ->right != nullptr){
            nodeStack.push_back(cur ->right);
            index++;   
        }
        while(cur != nullptr){
            TreeNode* left = cur -> left;
            cur -> left = nullptr;
            if(nodeStack.size() <= index){
                nodeStack.push_back(cur);
                index++;
            }else{
                nodeStack[index] = cur;
                index++;
            }
            cur = left;
        }
        
        for(int i =0;i<nodeStack.size();i++){
            cout<<nodeStack[i] -> val<<" ";
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        return now<max;
    }

    /** @return the next smallest number */
    int next() {
        if(cur == nullptr){
            index--;
            cur = nodeStack[index];
            nodeStack[index] = nullptr;
            return next();
        }
        if(cur -> left == nullptr){
            int ans = cur ->val;
            cur = cur -> right;
            now++;
            return ans;
        }else{
            while(cur != nullptr){
                TreeNode* left = cur -> left;
                cur -> left = nullptr;
                if(nodeStack.size() <= index){
                    nodeStack.push_back(cur);
                    index++;
                }else{
                    nodeStack[index] = cur;
                    index++;
                }
                cur = left;
            }
            return next();
        }
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
