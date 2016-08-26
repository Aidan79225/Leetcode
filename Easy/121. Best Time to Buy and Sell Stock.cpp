class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 )return 0;
        int ans=0,min,temp;
        min = prices[0];
        for(int i =1;i<prices.size();i++){
            if(min<prices[i]){
                temp = prices[i]-min;
                ans = ans < temp ? temp : ans;
            }else{
                min = prices[i];
            }
        }
        return ans;
    }
};
