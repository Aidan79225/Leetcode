class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans ;
        ans.resize(rowIndex+1);
        ans[0] =1;
        ans[1] =1;
        for(int i=2;i<=rowIndex;i++){
            for(int j=i;j>0;j--){
                ans[j] += ans[j-1]; 
            }
        }
        return ans;
        
    }
};
