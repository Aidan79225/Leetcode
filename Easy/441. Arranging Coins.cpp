class Solution {
public:
    int arrangeCoins(int n) {
        double x = 2.0*n+1.0/4.0;
        return (int)(newton(x));
    }
    double newton(double x){
	    double xhalf = 0.5*x;
	    long i = *(long*)&x; // get bits for floating VALUE 
    	i = 0x5fe6ec85e7de30da- (i>>1); // gives initial guess y0
	    x = *(double*)&i; // convert bits BACK to float
    	x = x*(1.5-xhalf*x*x); // Newton step, repeating increases accuracy
    	x = x*(1.5-xhalf*x*x); 
    	x = x*(1.5-xhalf*x*x); 
    	return (2.0-x)/(2.0*x);//   1/x - 1/2
    }  
};
