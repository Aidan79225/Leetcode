class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() ==0)return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count =0;
        int cookieIndex =0;
        for(int i=0;i<g.size();i++){
            while(s[cookieIndex] < g[i] && cookieIndex < s.size())cookieIndex++;
            if(cookieIndex == s.size())break;
            count++;
            cookieIndex++;
        }
        return count;
    }
};
