class Solution {
public:
    bool isPowerOfFour(int num) {
        double temp = log2((double)num) / log2((double)4.0);
        double eps = 0.00000001;
        if( myAbs(temp- (int)temp)< eps)return true;
        else return false;
    }
    double myAbs(double a){
        if(a>=0)return a;
        else return -a;
    }
};
