/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& temp) {
        if(temp.size() == 0)return temp;
        sort(temp.begin(), temp.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        vector<Interval> ans;
        Interval c = temp[0];
        for(auto& i : temp){
            if(i.start <= c.end){
                c.end = max(i.end, c.end);
            }else{
                ans.push_back(c);
                c = i;
            }
        }
        ans.push_back(c);
        return ans;
        
    }
   
};
