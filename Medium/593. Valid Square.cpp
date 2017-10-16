class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> line;
        vector<vector<int>> points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        for(int i = 0 ; i < 4; i++){
            for(int j = i + 1 ; j < 4; j++ ){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                line.push_back(dx * dx + dy * dy);
            }
        }
        for(int i = 1; i < line.size(); i++){
            if(line[0] == line[i]){
                line.erase(line.begin() + i);
                i--;
            }
        }
        line.erase(line.begin());
        if(line.size() == 4 || line.size() == 2){
            for(int i = 1; i < line.size(); i++){
                if(line[0] == line[i]){
                    line.erase(line.begin() + i);
                    i--;
                }
            }
            return line.size() == 1;
        }
        return false;
    }
};
