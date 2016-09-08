// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1,mid,r=n;
        while(r - l >1){
            mid = (r-l)/2 + l;
            if(isBadVersion(mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        return isBadVersion(l) ? l:r;
    }
};
