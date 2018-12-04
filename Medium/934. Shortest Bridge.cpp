class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    int shortestBridge(vector<vector<int>>& A) {
        int i = 0;
        int j = 0;
        findStart(i, j, A);
        markTable(i, j, A);
        toNegative(A);
        return compute(A);
        
    }
    
    void findStart(int& x, int& y, vector<vector<int>>& A){
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if(A[i][j] == 1){
                    x = i;
                    y = j;
                    return;
                }
            }
        }
    }
    
    void markTable(int i, int j, vector<vector<int>>& A){
        if(A[i][j] == 2 || A[i][j] == 0){
            return;
        }
        A[i][j] = 2;
        for(int c = 0; c < 4; c++){
            int ti = i + dx[c];
            int tj = j + dy[c];
            if(canAccess(ti, tj, A)){
                markTable(ti, tj, A);
            }
        }
    }
    
    void print(vector<vector<int>>& A){
        for(auto& i : A){
            for(auto& j : i){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
    
    void toNegative(vector<vector<int>>& A){
        for(auto& i : A){
            for(auto& j : i){
                j = -j;
            }
        }
    }
    
    int compute(vector<vector<int>>& A){
        vector<pair<int,int>> targetQ;
        vector<pair<int,int>> targetT;
        int ans = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j <A[i].size(); j++){
                if (A[i][j] == -2) {
                    targetQ.push_back(pair<int, int>(i,j));
                }
            }
        }
        while(true){
            ++ans;
            for(auto & it : targetQ) {
                for(int i = 0 ; i < 4; i++) {
                    int tx = it.first + dx[i];
                    int ty = it.second + dy[i];
                    if(canAccess(tx, ty, A)) {
                        if(A[tx][ty] == 0){
                            A[tx][ty] = ans;
                            targetT.push_back(pair<int, int>(tx,ty));
                        }else if(A[tx][ty] == -1) {
                            return ans-1;
                        }
                    }
                }
            }
            targetQ = targetT;
            targetT = vector<pair<int,int>>();
        }
        return ans;
    }
    
    bool canAccess(int i, int j, vector<vector<int>>& A){
        if(i < 0 || i >= A.size()){
            return false;
        }
        if(j < 0 || j >= A[i].size()){
            return false;
        }
        return true;
    }
};
