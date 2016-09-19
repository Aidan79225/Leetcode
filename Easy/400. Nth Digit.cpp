class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        while (n > len * 9 * pow(10, len - 1)) {
            n -= len * 9 * pow(10, len - 1);
            ++len;
        }

        int num = pow(10, len - 1) + (n - 1) / len;

        int nth = num / pow(10, (len - 1) - (n - 1) % len);
        nth %= 10;

        return nth;
    }
};

