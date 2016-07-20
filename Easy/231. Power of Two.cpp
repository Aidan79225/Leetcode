class Solution {
public:
    int find(int n){
        int temp =1;
        for(;;){
            if(temp<=0)break;
            if(temp<n){
                temp = temp<<1;
            }else
                break;
        }
        return temp;
    }
    bool isPowerOfTwo(int n) {
        return find(n) == n;
    }
};
