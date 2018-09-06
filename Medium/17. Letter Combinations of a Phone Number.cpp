class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> table;
        table.push_back("abc");
        table.push_back("def");
        table.push_back("ghi");
        table.push_back("jkl");
        table.push_back("mno");
        table.push_back("pqrs");
        table.push_back("tuv");
        table.push_back("wxyz");
        dfs(digits, 0, "", ans, table);
        return ans;
    }
    void dfs(string& digits, int index, string temp, vector<string>& ans, vector<string>& table){
        if(index == digits.length()){
            if(temp.length() > 0){
                ans.push_back(temp);   
            }
            return;
        }
        int tableIndex = digits[index] - '0' - 2;
        for(char c : table[tableIndex]){
            dfs(digits, index+1, temp+c, ans, table);
        }
    }
};
