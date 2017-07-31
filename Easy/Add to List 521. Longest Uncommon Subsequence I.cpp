class Solution {
public:
    int findLUSlength(string a, string b) {
        int as = a.size();
        int bs = b.size();
        if(as == bs) return a == b ? -1 : max(as,bs);
        else return max(as,bs);
    }
};
