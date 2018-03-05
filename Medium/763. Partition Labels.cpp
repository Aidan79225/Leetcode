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
        sort(temp.begin(), temp.end(), [](Interval i,Interval j) { return (i.start<j.start); });
        temp = reload(temp);
        
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
    
    vector<Interval> reload(vector<Interval>& temp){
        vector<Interval> ans;
        Interval c = temp[0];
        for(auto&i : temp){
            if(i.start <= c.end){
                c.end = max(i.end, c.end);
            }
            else{
                ans.push_back(c);
                c = i;
            }
        }
        ans.push_back(c);
        return ans;
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
