class Solution {
public:
    struct Node{
        int x;
        int y;
        int state;
        Node(int a = 0, int b = 0, int c = 0):
        x(a), y(b),state(c) {}
    };
    struct cmp{
    bool operator() ( Node a, Node b ){
        return a.state > b.state;
    }
    };
    

    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,1,-1,0};
    vector<vector<int>> used;
    priority_queue<Node,vector<Node>,cmp> mQ;
    int ans = -1;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size()-1;
        used = *new vector<vector<int>>(n+1,vector<int>(n+1,0));
        mQ.push(*new Node(0,0,grid[0][0]));
        dijkstra(n,grid);
        return ans;
    }
 
    void dijkstra(int n, vector<vector<int>>& grid){
        while(!mQ.empty()){
            Node temp = mQ.top();
            used[temp.x][temp.y] = 1;
            ans = max(ans, grid[temp.x][temp.y]);
            mQ.pop();
            if(temp.x == n && temp.y == n){
                return;
            }
            for(int i = 0 ; i < 4 ; i++){
                int newX = temp.x + dx[i];
                int newY = temp.y + dy[i];
                if(newX < 0 || newX > n || newY < 0 || newY > n || used[newX][newY] != 0){
                    continue;
                }
                mQ.push(*new Node(newX,newY,grid[newX][newY]));
            }
        }
    }
};
