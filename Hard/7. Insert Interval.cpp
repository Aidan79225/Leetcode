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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size() == 0)return vector<Interval>(1,newInterval);
        int start = 0;
        int end = intervals.size()-1;
        while(start < end && intervals[start].end < newInterval.start )start++;
        while(start < end && intervals[end].start > newInterval.end )end--;
        int tempStart = 0;
        int tempEnd = 0;
        if(intervals[start].start  > newInterval.end || intervals[start].end  < newInterval.start ){
            tempStart = newInterval.start;
        }else{
            tempStart = min(intervals[start].start,newInterval.start);
        }
        
        if(intervals[end].start  > newInterval.end || intervals[end].end  < newInterval.start ){
            tempEnd = newInterval.end;
            end--;
        }else{
            tempEnd = max(intervals[end].end,newInterval.end);
        }
        
        Interval temp(tempStart,tempEnd);
        intervals.erase(intervals.begin()+start,intervals.begin()+end + 1);
        insertInterval(temp,intervals);
        return intervals;
    }
    
    vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval) {
        insertInterval(newInterval,intervals);
        for(int i = 0 ; i < intervals.size() ; i++){
            for(int j = 0 ; j < intervals.size() ; j++){
                unionFunction(intervals[j],intervals[i]);
                Interval compare = intervals[j];
                removeInterval(compare,intervals);
                j = insertInterval(compare,intervals);
            }
        }
        return intervals;
    }
    void unionFunction(Interval& mInterval,Interval newInterval){
        if(mInterval.start  > newInterval.end || mInterval.end  < newInterval.start ){
            
        }else{
            mInterval.start = min(mInterval.start,newInterval.start);
            mInterval.end = max(mInterval.end,newInterval.end);
        }   
    }
    void removeInterval(Interval compare,vector<Interval>& intervals ){
        for(int i = 0 ; i < intervals.size() ; i++){
            Interval temp = intervals[i];
            if(temp.start >= compare.start && temp.end <= compare.end){
                intervals.erase(intervals.begin()+i);
                i--;
            }
        }
    }
    int insertInterval(Interval compare,vector<Interval>& intervals){
        for(int i = 0 ; i < intervals.size() ; i++){
            Interval temp = intervals[i];
            if(compare.start < temp.start){
                intervals.insert(intervals.begin()+i,compare);
                return i;
            }
        }
        intervals.insert(intervals.end(),compare);
        return intervals.size()-1;
    }
};
