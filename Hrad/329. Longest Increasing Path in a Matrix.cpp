class Solution {
public:
    void buildIsUsed(vector<vector<int>>& matrix,vector<vector<int>>& isUsed){
        for(int i=0;i<matrix.size();i++){
            vector<int> temp2;
            for(int j =0 ;j<matrix[i].size();j++){
                temp2.push_back(0);
            }
            isUsed.push_back(temp2);
        }
    }
    int DFS(vector<vector<int>>& matrix,vector<vector<int>>& isUsed,int x,int y){
        if(isUsed[x][y] != 0)return isUsed[x][y];
        
        else{
        int max1 =0;
        int max2 =0;
        int max3 =0;
        int max4 =0;
        
        if(x-1>=0               && matrix[x][y]<matrix[x-1][y])     max1 = DFS(matrix,isUsed,x-1,y);
        if(x+1<isUsed.size()    && matrix[x][y]<matrix[x+1][y])     max2 = DFS(matrix,isUsed,x+1,y);
        if(y-1>=0               && matrix[x][y]<matrix[x][y-1])     max3 = DFS(matrix,isUsed,x,y-1);
        if(y+1<isUsed[x].size() && matrix[x][y]<matrix[x][y+1])     max4 = DFS(matrix,isUsed,x,y+1);
        
        max2 = max1>max2?max1:max2;
        max3 = max3>max2?max3:max2;
        max4 = max4>max3?max4:max3;
        isUsed[x][y] = max4+1;
        return max4+1;
        }
        
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max =0;
        vector<vector<int>> isUsed;
        buildIsUsed(matrix,isUsed);
        for(int i=0;i<matrix.size();i++){
            for(int j =0 ;j<matrix[i].size();j++){
                int temp = DFS(matrix,isUsed,i,j);
                if(temp>max)
                    max=temp;
            }
        }
        
        return max;
        
    }
};
