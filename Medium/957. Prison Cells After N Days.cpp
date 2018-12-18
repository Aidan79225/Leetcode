class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int day = 0;
        vector<int> cIndex(512, -1);
        bool hasAns = false;
        int circle = 0;
        int start = 0;
        while (day <= N) {
            if(day == N){
                return cells;
            }
            int id = getId(cells);
            if(cIndex[id] > 0){
                hasAns = true;
                circle = day - cIndex[id];
                start = cIndex[id];
                break;
            } else {
                cIndex[id] = day;
                cells = progress(cells);
            }
            day++;
        }
        if (hasAns) {
            unordered_map<int, int> mMap;
            for (int i = 0; i < 512; ++i) {
                mMap[cIndex[i]] = i;
            }  
            return parseId(mMap[(N-start) % circle + start]);
        } 
        
        
        return cells;
    }
    
    void print(vector<int> &cells){
        for(auto& it : cells){
            cout<<it<<", ";
        }
        cout<<endl;
    }
    
    vector<int> progress(vector<int> &cells) {
        vector<int> ans(8,0);
        for (int i = 1; i < 7; i++) {
            ans[i] = !(cells[i-1] ^ cells[i+1]);
        }
        return ans;
    }
    
    
    int getId(vector<int>& cells) {
        int id = 0;
        for(int i = 0; i < 8; ++i) {
            id = ((id<<1) | cells[i]);
        }
        return id;
    }
    
    vector<int> parseId(int id){
        vector<int> ans(8,0);
        for(int i = 7; i >= 0; --i) {
            ans[i] = (0b1 & id);
            id = (id>>1);
        }
        return ans;
    }
};
