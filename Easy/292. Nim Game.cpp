class Solution {
public:
    bool canWinNim(int n) {
        if(n == 0)return false;
        else if(n<4)return true; 
        int k = n <<30;
        k = k>>30;
        if(k == 0)return false;
        else if(k<4)return true; 
        return true;
    }
};
