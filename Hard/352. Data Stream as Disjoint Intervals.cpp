/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    vector<Interval> ans;
    SummaryRanges() {
    
    }
    
    void addNum(int val) {
        int l = 0;
        int r = ans.size();
        int mid;
        while(l<r){
            mid = l + (r-l)/2;
            if((ans[mid].start) <= val && (ans[mid].end >= val)){
                return;
            }else if(ans[mid].start > val){
                r = mid;
            }else if(ans[mid].end < val){
                l = mid+1;
            }
        }
        

        Interval i(val,val);
        ans.insert(ans.begin()+l,i);
        int size = ans.size()-1;
        for(int k = 0 ; k < size ; k++){
           if(ans[k].end + 1 >= ans[k+1].start){
               ans[k].end = ans[k+1].end;
               ans.erase(ans.begin()+k+1);
               size = ans.size()-1;
               k--;
           }
        }
    }
    
    
    vector<Interval> getIntervals() {
        return ans;   
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
