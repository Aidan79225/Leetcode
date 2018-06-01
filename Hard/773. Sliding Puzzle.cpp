class Solution {
public:
    unordered_map<int,vector<int>> moveStep = 
    {
        { 0, { 1, 3 }},
        { 1, { 0, 2, 4 }},
        { 2, { 1, 5 }},
        { 3, { 0, 4 }},
        { 4, { 1, 3, 5 }},
        { 5, { 4, 2}}
        };
    queue<pair<string,int>> mQueue;
    unordered_set<string> history;
    string checkString = "123450";
    int slidingPuzzle(vector<vector<int>>& board) {
        string puzzle = "";
        for(auto& i : board){
            for( auto& j : i){
                puzzle += to_string(j);
            }
        }
        mQueue.push({puzzle,0});
        return bfs();
    }
    
    int bfs(){
        if(mQueue.empty()){
            return -1;
        }
        string now = mQueue.front().first;
        int step = mQueue.front().second;
        if(check(now)){
            return step;
        }
        mQueue.pop();
        int zero = findZero(now);
        
        for(int i : moveStep[zero]){
            string nextString = getNextString(now,zero,i);
            if(history.find(nextString) == history.end()){
                mQueue.push({nextString,step+1});
                history.insert(nextString);
            }
        }
        return bfs();
    }
    
    int findZero(string now){
        for(int i = 0 ; i < now.size() ; i++){
            if(now[i] == '0'){
                return i;
            }
        }
        return -1;
    }
    
    string getNextString(string now, int zero, int nextZero){
        swap(now[zero], now[nextZero]);
        return now;
    }
    
    bool check(string now){
        for(int i = 0 ; i < 6 ; i++){
            if(now[i] != checkString[i]){
                return false;
            }
        }
        return true;
    }
    
};
