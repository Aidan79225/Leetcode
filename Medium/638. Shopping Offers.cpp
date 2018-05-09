class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price,special, needs);
    }
    
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs){
        int ans = getUnitPrice(price,needs);
        for(auto& it : special){
            vector<int> t(needs.begin(), needs.end());
            bool can = true;
            for(int i = 0 ; i < needs.size() ; i++){
                t[i] -= it[i];
                if(t[i] < 0){
                    can = false;
                    break;
                }
            }
            if(can){
                int k = it[it.size()-1] + dfs(price,special, t);
                if(k < ans && k >= 0){
                    ans = k;
                }   
            }
        }
        return ans;
    }
    int getUnitPrice(vector<int>& price, vector<int> needs){
        int ans = 0;
        for(int i = 0 ; i < price.size() ; i++){
            ans += price[i] * needs[i];
        }
        return ans;
    }
};
