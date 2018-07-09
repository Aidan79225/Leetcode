class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size()-1;
        int mid = ((l + r)>>1);
        int size = citations.size();
        while(l <= r){
            int t = size-mid;
            if(t > citations[mid]){
                l = mid + 1;
            }else if(t <= citations[mid]){
                r = mid - 1;
            }
            mid = ((l + r)>>1);
        }
        return size - l;
    }
};
