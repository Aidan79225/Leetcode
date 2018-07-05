class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n, 0);
        ans[0] = 0;
        ans[1] = 1;
        int maxS = (1 << n);
        int size = 2;
        int hsize = 0;
        int add = 0b1;
        int count = 2;
        while(count < maxS){
            add = (add << 1);
            hsize = size;
            size = size << 1;
            for(int i = hsize, j = 1 ; i < size && count < maxS ; i++, j++){
                ans[i] = ans[hsize - j] | add;
                count++;
            }
        }
        
        return ans;
    }
};
