class Solution {
public:

    int cost(int left,int right,vector<vector<int>>& costTemp){
        if(right-left==1)return left;
        else if(right-left < 1)return 0;
        else if(costTemp[left][right] !=0)return costTemp[left][right];
        int min = 2147483647;
        for(int i = right-1;i >= left+1; i--){
            int temp =i+ max(cost(left,i-1,costTemp),cost(i+1,right,costTemp));
            if(min> temp)
                min = temp;
        }
        costTemp[left][right] = min;
        return min;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> costTemp(n + 1, vector<int>(n + 1, 0));
        return cost(1,n,costTemp);
    }
};
