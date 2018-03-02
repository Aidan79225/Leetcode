    class Solution {
        public:
        bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
            int k = abs(target[0]) + abs(target[1]);
            for(auto &it : ghosts){
                if( k >= getLength(it,target)){
                    return false;
                }
            }
            return true;
        }
        
        int getLength(vector<int> p, vector<int> t){
            return abs(p[1] - t[1]) + abs( p[0] - t[0]);
        }
        
        bool escapeGhosts2(vector<vector<int>>& ghosts, vector<int>& target) {
            vector<int> my;
            my.push_back(0);
            my.push_back(0);
            while(!move(my,target)){
                for(auto& it : ghosts){
                    if(move(it,target) || isEqual(it,my)){
                           return false;
                    } 
                }
            }
            return true;
        }
        bool move(vector<int>& p, vector<int> t){
            if(p[0] == t[0]){
                if(p[1] == t[1]){
                    return true;
                }else{
                    p[1] += (t[1] - p[1]) > 0 ? 1 : -1;
                }
            }else{
                p[0] += (t[0] - p[0]) > 0 ? 1 : -1;
            }
            return false;
        }
        bool isEqual(vector<int> p, vector<int> t){
            return p[0] == t[0] && p[1] == t[1];
        }
};

