class Solution {
public:
    int flipLights(int n, int m) {
        return m == 0 ? 1 : (n == 1 ? 2 : (n == 2 ? (m == 1 ? 3 : 4) : (m == 1 ? 4 : (m == 2 ? 7 : 8))));
    }
};
