class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if(grid.size() == 0)return 0;
        if(grid[0].size() == 0)return 0;
        int x[grid.size()];
        int y[grid[0].size()];
        for(int i = 0 ; i < grid.size() ; i++){
            int t = 0;
            for(int j = 0 ; j < grid[i].size() ;j++){
                t = max(t, grid[i][j]);
            }
            x[i] = t;
        }
        
        for(int i = 0 ; i < grid[0].size() ; i++){
            int t = 0;
            for(int j = 0 ; j < grid.size() ;j++){
                t = max(t, grid[j][i]);
            }
            y[i] = t;
        }
        
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ;j++){
                ans += max(min(x[i],y[j]) - grid[i][j],0);
            }
        }
        return ans;
        
    }
};
