class Solution {
public:
    int findComplement(int num) {
        int ans =0;
        int index = 0;
        while(num >0){
            ans += ((1-(num % 2)) << index );
            index++;
            num = (num >> 1);
        }
        return ans;
    }
};
