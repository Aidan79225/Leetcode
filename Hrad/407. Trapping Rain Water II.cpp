class Solution {
public:
    class Point{
        public:
            int h = 2147483647;
            int x = 0;
            int y = 0;
    };
    class mComparison{
        public:
            bool operator() (const Point& lhs, const Point&rhs) const{
                return (lhs.h-rhs.h);
            }
    };
    
    struct cmp{
        bool operator() (const Point& lhs, const Point& rhs) {
            return lhs.h > rhs.h;
        }
    };
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int maxX = 0;
    int maxY = 0;
    bool isConform(int x, int y){
        return x >=0 && x< maxX && y >= 0 && y < maxY;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() == 0)return 0;
        if(heightMap[0].size() == 0)return 0;
        maxX = heightMap.size();
        maxY = heightMap[0].size();
        priority_queue< Point, vector<Point>, cmp >  pq;
        bool visited[maxX][maxY] = {false};
        for(int i = 0 ; i < maxX ; i++){
            visited[i][0] = true;
            visited[i][maxY-1] = true;
            Point* p = new Point();
            p -> h = heightMap[i][0];
            p -> x = i;
            p -> y = 0;
            pq.push(*p);
            Point* q = new Point();
            q -> h = heightMap[i][maxY-1];
            q -> x = i;
            q -> y = maxY-1;
            pq.push(*q);
        }
        
        for(int i = 0 ; i < maxY ; i++){
            visited[0][i] = true;
            visited[maxX-1][i] = true;
            Point* p = new Point();
            p -> h = heightMap[0][i];
            p -> x = 0;
            p -> y = i;
            pq.push(*p);
            Point* q = new Point();
            q -> h = heightMap[maxX-1][i];
            q -> x = maxX -1;
            q -> y = i;
            pq.push(*q);
        }
        int ans = 0;        
        while (!pq.empty()) {
            Point p = pq.top();
            for (int i = 0 ; i < 4 ; i++) {
                int x = p.x + dx[i];
                int y = p.y + dy[i];
                if (isConform(x,y) && !visited[x][y]) {
                    visited[x][y] = true;
                    ans += max(0, p.h - heightMap[x][y]);
                    Point* q = new Point();
                    q -> h = max(heightMap[x][y],p.h);
                    q -> x = x;
                    q -> y = y;
                    pq.push(*q);
                }
            }
            pq.pop();
        }
        return ans;
    }
};
