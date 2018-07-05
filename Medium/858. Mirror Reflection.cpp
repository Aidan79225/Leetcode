class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / gcd(q, p);
        int k = lcm / p;
        int n = lcm / q;
        if(k & 0b1){
            if(n & 0b1){
                return 1;
            }else{
                return 2;
            }
        }else{
            if(n & 0b1){
                return 0;
            }else{
                return -1;
            }
        }
        return lcm;
    }
    int gcd(int a, int b){
        if(a > b){
            return gcd(b, a);
        }
        if(b % a == 0)return a;
        else return gcd(b % a, a);
    }  
    
};
