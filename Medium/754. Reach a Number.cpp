class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1.0 + 8.0 * target))/2.0 );
        long long sum = (n * (n + 1) )>> 1;
        if (sum == target) return n;
        return (sum - target)&1 ? n+((n&1) ? 2 : 1) : n;
    }
};
