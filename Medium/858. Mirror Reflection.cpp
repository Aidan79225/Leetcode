class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / gcd(q, p);
        int k = lcm / p;
        int n = lcm / q;
        return (k & 0b1) ? (n & 0b1 ? 1 : 2) : (n & 0b1 ? 0 : -1);
    }
    int gcd(int a, int b){
        if(b)while((b %= a) && (a %= b));
        return a + b;
    }  
};
