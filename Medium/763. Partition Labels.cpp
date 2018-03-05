class Solution {
public:
    class Interval {
        public:
            int start;
            int end;
            Interval() : start(0), end(0) {}
            Interval(int s, int e) : start(s), end(e) {}
    };
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<Interval> temp;
        for(int i = 'a' ; i <= 'z' ; i++){
            insert(temp, find(S,i));
        }
        reload(temp);
        sort(temp.begin(), temp.end(), [](Interval i,Interval j) { return (i.start<j.start); });
        for(auto& it : temp){
            ans.push_back(it.end - it.start +1);
        }
        return ans;
    }
    void insert(vector<Interval>& temp, Interval t){
        if(t.start == -1){
            return;
        }
        temp.push_back(t);
    }
    
    void reload(vector<Interval>& temp){
        bool needReload = false;
        for(int i = 0 ; i < temp.size()-1 ; i++){
            for(int j = i+1 ; j < temp.size() ; j++){
                if(needMerge(temp[i],temp[j])){
                    temp[i].end = max(temp[i].end, temp[j].end);
                    temp[i].start = min(temp[i].start, temp[j].start);
                    temp.erase(temp.begin()+j);
                    j--;
                    needReload = true;
                }
            }
        }
        if(needReload){
            reload(temp);
        }
    }
    
    bool needMerge(Interval it , Interval t){
        if(it.end <= t.end && it.end >= t.start){
            return true;
        }
        if(it.start <= t.end && it.start >= t.start){
            return true;
        }
        if(t.end <= it.end && t.end >= it.start){
            return true;
        }
        if(t.start <=it.end && t.start >= it.start){
            return true;
        }
        return false;
    }
    Interval find(string S, char t){
        int s,e;
        s = strchr(S,t);
        e = strrchr(S,t);
        return *new Interval(s,e);
    }
    int strchr(string S, char t){
        for(int i = 0 ; i < S.size() ; i++){
            if(S[i] == t){
                return i;
            }
        }
        return -1;
    }
    
    int strrchr(string S, char t){
        for(int i = S.size()-1 ; i >= 0 ; i--){
            if(S[i] == t){
                return i;
            }
        }
        return -1;
    }
};
