class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0)return ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows == 1)return ans;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows == 2)return ans;
        for(int i = 3; i <= numRows; i++){
            temp.push_back(1);
            for(int j=1;j<i-1;j++){
                temp[j] = ans[i-2][j-1]+ans[i-2][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
