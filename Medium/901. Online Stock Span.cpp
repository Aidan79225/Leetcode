class StockSpanner {
public:
    vector<int> prices;
    vector<int> span;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int size = prices.size();
        if(size == 0 || prices[size-1] > price){
            prices.push_back(price);
            span.push_back(1);
            return 1;
        }else{
            int ans = 1;
            int i = prices.size()-1;
            while(i >= 0 && prices[i] <= price){
                ans += span[i];
                i -= span[i];
            }
            prices.push_back(price);
            span.push_back(ans);
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
