class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *count = new int[amount+1];
        int size = coins.size();
        if(size == 0 )return -1;
        for(int i=0;i<=amount;i++){
            count[i] = -1;
        }
        count[0]=0;
        
        for(int i=1;i<=amount;i++){
            int mintemp =INT_MAX;
            bool flag =true;
            for(int j=0;j<size;j++){
                int temp = i - coins[j];
                if(temp < 0 ||count[temp]<0 )continue;
                flag = false;
                mintemp = min(mintemp,count[temp]+1);
            }
            count[i] = flag?-1: mintemp;
        }
        
        return count[amount];
    }
};
