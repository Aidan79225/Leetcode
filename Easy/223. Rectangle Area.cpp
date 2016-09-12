class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int blx = max(A, E);  
        int bly = max(B, F);  
        int rtx = min(C, G);  
        int rty = min(D, H);  
        int res = (C-A) * (D-B) + (G-E) * (H-F);  
        if(blx >= rtx || bly >= rty) return res;  
        return res - (rtx - blx) * (rty - bly);  
    }
};
