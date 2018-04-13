class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        dfs(ans, temp, 0, 0, n << 1,n);
        return ans;
    }
    void dfs(vector<string>& ans, string& temp, int index, int leftN, int n, int half){
        if(index == n){
            if(leftN == 0){
                ans.push_back(temp);   
            }
            return;
        }
        if(leftN < 0 || leftN > half){
            return;
        }
        if(leftN < half){
            temp.push_back('(');
            dfs(ans, temp, index+1, leftN + 1, n, half);
            temp.pop_back();    
        }
        
        temp.push_back(')');
        dfs(ans, temp, index+1, leftN - 1, n, half);
        temp.pop_back();
        
    }
};
